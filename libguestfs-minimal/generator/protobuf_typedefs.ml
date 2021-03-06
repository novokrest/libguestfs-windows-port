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
let generate_protobuf_typedefs () =
  generate_header ~emacs_mode:"c" CStyle LGPLv2plus;

  pr "#ifndef _GUESTFS_PROTOBUF_PROTOCOL_TYPEDEFS_H_\n";
  pr "#define _GUESTFS_PROTOBUF_PROTOCOL_TYPEDEFS_H_\n";
  pr "\n";
(*  pr "#include \"guestfs_protocol.pb-c.h\"\n"; *)
  pr "\n";
  pr "/* Internal structures. */\n";
  pr "\n";
  List.iter (
    fun { s_name = name; s_camel_name = camel_name } ->
        pr "typedef GuestfsProtobufInt%s guestfs_protobuf_int_%s;\n" camel_name name;
        pr "typedef GuestfsProtobufInt%sList guestfs_protobuf_int_%s_list;\n" camel_name name;
        pr "\n";
  ) structs;

  pr "/* Function arguments and return values. */\n";
  pr "\n";
  List.iter (
    fun { name = shortname; camel_name = camel_shortname; style = ret, args, optargs } ->
      let name = "guestfs_protobuf_" ^ shortname in
      let camel_name = "GuestfsProtobuf" ^ camel_shortname in

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
        pr "typedef %sArgs %s_args;\n" camel_name name;
        pr "\n"
      );
      (match ret with
       | RErr -> ()
       | r ->
         pr "typedef %sRet %s_ret;\n" camel_name name;
         pr "\n"
      );
  ) daemon_functions;
(*
  pr "/* Table of procedure numbers. */\n";
  pr "typedef enum GuestfsProtobufProcedure guestfs_protobuf_procedure;\n";
  let rec loop = function
    | [] -> ()
    | { proc_nr = None } :: _ -> assert false
    | { name = shortname; proc_nr = Some proc_nr } :: rest ->
      pr "  #define GUESTFS_PROC_%s GUESTFS_PROTOBUF_PROCEDURE__GUESTFS_PROTOBUF_PROC_%s\n" (String.uppercase shortname) (String.uppercase shortname);
      loop rest
  in
  loop daemon_functions;
  pr "\n";

  (* Message header, etc. *)
  pr "typedef enum GuestfsProtobufConst guestfs_protobuf_const;\n";
  
  pr "\  
  #define GUESTFS_PROGRAM GUESTFS_PROTOBUF_CONST__GUESTFS_PROTOBUF_PROGRAM
  #define GUESTFS_PROTOCOL_VERSION GUESTFS_PROTOBUF_CONST__GUESTFS_PROTOBUF_PROTOCOL_VERSION
  #define GUESTFS_MAX_CHUNK_SIZE GUESTFS_PROTOBUF_CONST__GUESTFS_PROTOBUF_MAX_CHUNK_SIZE

/* These constants must be larger than any possible message length. */
  #define GUESTFS_LAUNCH_FLAG GUESTFS_PROTOBUF_CONST__GUESTFS_PROTOBUF_LAUNCH_FLAG
  #define GUESTFS_CANCEL_FLAG GUESTFS_PROTOBUF_CONST__GUESTFS_PROTOBUF_CANCEL_FLAG
  #define GUESTFS_PROGRESS_FLAG GUESTFS_PROTOBUF_CONST__GUESTFS_PROTOBUF_PROGRESS_FLAG
  #define GUESTFS_SHARED_MEMORY_FLAG GUESTFS_PROTOBUF_CONST__GUESTFS_PROTOBUF_SHARED_MEMORY_FLAG

";
  pr "  #define GUESTFS_ERROR_LEN GUESTFS_PROTOBUF_CONST__GUESTFS_PROTOBUF_ERROR_LEN\n";
  pr "\n";
  
  pr "  #define GUESTFS_MAX_PROC_NR GUESTFS_PROTOBUF_CONST__GUESTFS_PROTOBUF_MAX_PROC_NR\n";
  pr "\n";

  pr "/* The remote procedure call protocol. */\n";
  pr "\n";

  (* Having to choose a maximum message size is annoying for several
   * reasons (it limits what we can do in the API), but it (a) makes
   * the protocol a lot simpler, and (b) provides a bound on the size
   * of the daemon which operates in limited memory space.
   *)
  pr "  #define GUESTFS_MESSAGE_MAX GUESTFS_PROTOBUF_CONST__GUESTFS_PROTOBUF_MESSAGE_MAX\n";
  pr "\n";

  pr "\
typedef enum GuestfsMessageDirection guestfs_message_direction;
  #define GUESTFS_DIRECTION_CALL GUESTFS_PROTOBUF_MESSAGE_DIRECTION__GUESTFS_PROTOBUF_DIRECTION_CALL         /* client -> daemon */
  #define GUESTFS_DIRECTION_REPLY GUESTFS_PROTOBUF_MESSAGE_DIRECTION__GUESTFS_PROTOBUF_DIRECTION_REPLY        /* daemon -> client */

typedef enum GuestfsMessageStatus guestfs_message_status;
  #define GUESTFS_STATUS_OK GUESTFS_PROTOBUF_MESSAGE_STATUS__GUESTFS_PROTOBUF_STATUS_OK
  #define GUESTFS_STATUS_ERROR GUESTFS_PROTOBUF_MESSAGE_STATUS__GUESTFS_PROTOBUF_STATUS_ERROR

";
*)
  pr "\n";
  pr "\
typedef GuestfsProtobufMessageError guestfs_protobuf_message_error;
typedef GuestfsProtobufMessageHeader guestfs_protobuf_message_header;
typedef GuestfsProtobufChunk guestfs_protobuf_chunk;
typedef GuestfsProtobufShmChunk guestfs_protobuf_shm_chunk;
typedef GuestfsProtobufProgress guestfs_protobuf_progress;
typedef GuestfsProtobufFlagMessage guestfs_protobuf_flag_message;

typedef size_t (*protobuf_proc_pack) (ProtobufCMessage *message, uint8_t *out);
typedef ProtobufCMessage* (*protobuf_proc_unpack) (ProtobufCAllocator *allocator, size_t len, const uint8_t *data);

";

pr "#endif /* _GUESTFS_PROTOBUF_PROTOCOL_TYPEDEFS_H_ */"
