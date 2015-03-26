(* libguestfs
 * Copyright (C) 2009-2014 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *)

(* Please read generator/README first. *)

open Printf

open Types
open Utils
open Pr
open Docstrings
open Optgroups
open Actions
open Structs

(* Generate the protocol (XDR) file, 'guestfs_protocol.x' and
 * indirectly 'guestfs_protocol.h' and 'guestfs_protocol.c'.
 *
 * We have to use an underscore instead of a dash because otherwise
 * rpcgen generates incorrect code.
 *
 * This header is NOT exported to clients, but see also generate_structs_h.
 *)
let generate_protobuf () =
  generate_header ~emacs_mode:"c" CStyle LGPLv2plus;

  pr "/* This file defines the protocol used between the library and\n";
  pr " * the appliance/daemon.  For more information see the COMMUNICATION\n";
  pr " * PROTOCOL section in guestfs(3).  Note this protocol is internal\n";
  pr " * to libguestfs and may change at any time.\n";
  pr " */\n";
  pr "\n";

  pr "/* Internal structures. */\n";
  pr "\n";
  List.iter (
    fun { s_name = typ; s_cols = cols } ->
        pr "message GuestfsInt%s {\n" (camel_name_of_struct typ);
        List.iteri (fun id col ->
                      match col with
                       | name, FChar -> pr "  required int32 %s = %d;\n" name (id + 1)
                       | name, FString -> pr "  required string %s = %d;\n" name (id + 1)
                       | name, FBuffer -> pr "  required bytes %s = %d;\n" name (id + 1)
                       | name, FUUID -> pr "  required bytes %s = %d;\n" name (id + 1)
                       | name, FInt32 -> pr "  required int32 %s = %d;\n" name (id + 1)
                       | name, FUInt32 -> pr "  required uint32 %s = %d;\n" name (id + 1)
                       | name, (FInt64|FBytes) -> pr "  required int64 %s = %d;\n" name (id + 1)
                       | name, FUInt64 -> pr "  required uint64 %s = %d;\n" name (id + 1)
                       | name, FOptPercent -> pr "  required float %s = %d;\n" name (id + 1)
                   ) cols;
        pr "}\n";
        pr "\n";
        pr "message GuestfsInt%sList {\n" (camel_name_of_struct typ);
        pr "  repeated GuestfsInt%s vals = 1;" (camel_name_of_struct typ);
        pr "}\n";
        pr "\n";
  ) structs;

  pr "/* Function arguments and return values. */\n";
  pr "\n";
  List.iter (
    fun { camel_name = shortname; style = ret, args, optargs } ->
      let name = "Guestfs" ^ shortname in

      (* Ordinary arguments and optional arguments are concatenated
       * together in the ProtoBuf args message.  The optargs_bitmask field
       * in the header controls which optional arguments are
       * meaningful.  FileIn/FileOut parameters are ignored here.
       *)
      let args_passed_to_daemon = args @ args_of_optargs optargs in
      let args_passed_to_daemon =
        List.filter (function FileIn _ | FileOut _ -> false | _ -> true)
          args_passed_to_daemon in
      (match args_passed_to_daemon with
      | [] -> ()
      | args ->
        pr "message %sArgs {\n" name;
        List.iteri (
          fun id argt ->
            match argt with
             | Pathname n | Device n | Mountable n | Dev_or_Path n
             | Mountable_or_Path n | String n
             | Key n | GUID n ->
               pr "  required string %s = %d;\n" n (id + 1)
             | OptString n -> pr "  required string %s = %d;\n" n (id + 1)
             | StringList n | DeviceList n -> pr "  repeated string %s = %d;\n" n (id + 1)
             | Bool n -> pr "  required bool %s = %d;\n" n (id + 1)
             | Int n -> pr "  required int32 %s = %d;\n" n (id + 1)
             | Int64 n -> pr "  required int64 %s = %d;\n" n (id + 1)
             | BufferIn n ->
               pr "  required bytes %s = %d;\n" n (id + 1)
             | FileIn _ | FileOut _ | Pointer _ -> assert false
        ) args;
        pr "}\n\n"
      );
      (match ret with
       | RErr -> ()
       | RInt n ->
           pr "message %sRet {\n" name;
           pr "  required int32 %s = 1;\n" n;
           pr "}\n\n"
       | RInt64 n ->
           pr "message %sRet {\n" name;
           pr "  required int64 %s = 1;\n" n;
           pr "}\n\n"
       | RBool n ->
           pr "message %sRet {\n" name;
           pr "  required bool %s = 1;\n" n;
           pr "}\n\n"
       | RConstString _ | RConstOptString _ ->
           failwithf "RConstString|RConstOptString cannot be used by daemon functions"
       | RString n ->
           pr "message %sRet {\n" name;
           pr "  required string %s = 1;\n" n;
           pr "}\n\n"
       | RStringList n ->
           pr "message %sRet {\n" name;
           pr "  repeated string %s = 1;\n" n;
           pr "}\n\n"
       | RStruct (n, typ) ->
           pr "message %sRet {\n" name;
           pr "  required GuestfsInt%s %s = 1;\n" (camel_name_of_struct typ) n;
           pr "}\n\n"
       | RStructList (n, typ) ->
           pr "message %sRet {\n" name;
           pr "  required GuestfsInt%sList %s = 1;\n" (camel_name_of_struct typ) n;
           pr "}\n\n"
       | RHashtable n ->
           pr "message %sRet {\n" name;
           pr "  repeated string %s = 1;\n" n;
           pr "}\n\n"
       | RBufferOut n ->
           pr "message %sRet {\n" name;
           pr "  required bytes %s = 1;\n" n;
           pr "}\n\n"
      );
  ) daemon_functions;

  pr "/* Table of procedure numbers. */\n";
  pr "enum GuestfsProcedure {\n";
  let rec loop = function
    | [] -> ()
    | { proc_nr = None } :: _ -> assert false
    | { name = shortname; proc_nr = Some proc_nr } :: rest ->
      pr "  GUESTFS_PROC_%s = %d;\n" (String.uppercase shortname) proc_nr;
      loop rest
  in
  loop daemon_functions;
  pr "}\n";
  pr "\n";

  (* Message header, etc. *)
  pr "enum GuestfsConst {\n";
  
  pr "\  
  GUESTFS_PROGRAM = 0x2000F5F5;
  GUESTFS_PROTOCOL_VERSION = 4;
  GUESTFS_MAX_CHUNK_SIZE = 8192;

/* These constants must be larger than any possible message length. */
  GUESTFS_LAUNCH_FLAG = 0x75f55ff5;
  GUESTFS_CANCEL_FLAG = 0x7fffeeee;
  GUESTFS_PROGRESS_FLAG = 0x7fff5555;

";
  pr "  GUESTFS_ERROR_LEN = %d;\n" (64 * 1024);
  pr "\n";
  
  pr "  GUESTFS_MAX_PROC_NR = %d;\n" max_proc_nr;
  pr "\n";

  pr "/* The remote procedure call protocol. */\n";
  pr "\n";

  (* Having to choose a maximum message size is annoying for several
   * reasons (it limits what we can do in the API), but it (a) makes
   * the protocol a lot simpler, and (b) provides a bound on the size
   * of the daemon which operates in limited memory space.
   *)
  pr "  GUESTFS_MESSAGE_MAX = %d;\n" (4 * 1024 * 1024);
  pr "\n";
  
  pr "}\n\n"; (* End of GUESTFS_CONST *)

  pr "\
enum GuestfsMessageDirection {
  GUESTFS_DIRECTION_CALL = 0;         /* client -> daemon */
  GUESTFS_DIRECTION_REPLY = 1;        /* daemon -> client */
}

enum GuestfsMessageStatus {
  GUESTFS_STATUS_OK = 0;
  GUESTFS_STATUS_ERROR = 1;
}

";

  pr "\
message GuestfsMessageError {
  required string errno_string = 1;           /* errno eg. \"EINVAL\", empty string
                                                 if errno not available */
  required string error_message = 2;
}

message GuestfsMessageHeader {
  required fixed32 prog = 1;                         /* GUESTFS_PROGRAM */
  required fixed32 vers = 2;                         /* GUESTFS_PROTOCOL_VERSION */
  required sfixed32 proc = 3;                        /* GUESTFS_PROC_x */
  required sfixed32 direction = 4;
  required fixed32 serial = 5;                       /* message serial number */
  required fixed64 progress_hint = 6;                /* upload hint for progress bar */
  required fixed64 optargs_bitmask = 7;              /* bitmask for optional args */
  required sfixed32 status = 8;
}

message GuestfsChunk {
  required int32 cancel = 1;     /* if non-zero, transfer is cancelled */
  /* data size is 0 bytes if the transfer has finished successfully */
  required bytes data = 2;
}

/* Progress notifications.  Daemon self-limits these messages to
 * at most one per second.  The daemon can send these messages
 * at any time, and the caller should discard unexpected messages.
 * 'position' and 'total' have undefined units; however they may
 * have meaning for some calls.
 *
 * Notes:
 *
 * (1) guestfs___recv_from_daemon assumes the XDR-encoded
 * structure is 24 bytes long.
 *
 * (2) daemon/proto.c:async_safe_send_pulse assumes the progress
 * message is laid out precisely in this way.  So if you change
 * this then you'd better change that function as well.
 */
message GuestfsProgress {
  required sfixed32 proc = 1;                    /* @0:  GUESTFS_PROC_x */
  required fixed32 serial = 2;                   /* @4:  message serial number */
  required fixed64 position = 3;                 /* @8:  0 <= position <= total */
  required fixed64 total = 4;                    /* @16: total size of operation */
                                                 /* @24: size of structure */
}

message GuestfsFlagMessage {
  required fixed32 val = 1;
}
"
