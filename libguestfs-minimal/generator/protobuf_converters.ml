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
 
let generate_converters_header () = 
  generate_header ~emacs_mode:"c" CStyle LGPLv2plus;
  
  pr "#ifndef GUESTFS_PROTOCOL_CONVERTERS_H_\n";
  pr "#define GUESTFS_PROTOCOL_CONVERTERS_H_\n";
  
  pr "#include \"guestfs_protocol.h\"\n";
  
  List.iter (
    fun { s_name = s_name } ->
      pr "struct guestfs_%s;\n" s_name
  ) structs;
  
    List.iter (
    fun { s_name = s_name } ->
        pr "void\n";
        pr "convert_guestfs_%s_xdr_to_protobuf (guestfs_h *g, \n" s_name;
        pr "                                    struct guestfs_%s *xdr,\n" s_name;
        pr "                                    guestfs_int_%s *pbc);\n" s_name;

        pr "\n";
        
        pr "void\n";
        pr "convert_guestfs_%s_protobuf_to_xdr (guestfs_h *g, \n" s_name;
        pr "                                    guestfs_int_%s *pbc,\n" s_name;
        pr "                                    struct guestfs_%s *xdr);\n" s_name;
        
        pr "\n"
  ) structs;
  
  pr "#endif /* GUESTFS_PROTOCOL_CONVERTERS_H_ */"
  
let generate_converters () =
  generate_header ~emacs_mode:"c" CStyle LGPLv2plus;

  pr "/* This file defines convert functions from structs used in xdr\n";
  pr " * to structs (aka messages) used in protobuf-c\n";
  pr " */\n";
  pr "\n";
  
  pr "#include \"guestfs.h\"\n";

  pr "/* Converters for structs\n";
  pr " * from xdr to protobuf representation and vice versa.\n";
  pr "*/\n";
  pr "\n";

  List.iter (
    fun { s_name = s_name; s_cols = cols } ->
        pr "void\n";
        pr "convert_guestfs_%s_xdr_to_protobuf (guestfs_h *g, \n" s_name;
        pr "                                    struct guestfs_%s *xdr,\n" s_name;
        pr "                                    guestfs_int_%s *pbc)\n" s_name;
        pr "{\n";
        List.iter (function
                   | name, FChar -> 
                     pr "  pbc->%s = xdr->%s;\n" name name
                   | name, FString -> 
                     pr "  pbc->%s = safe_strdup (g, xdr->%s);\n" name name
                   | name, FBuffer -> 
                     pr "  pbc->%s.data = safe_memdup (g, xdr->%s.%s_val, xdr->%s.%s_len); \n" name name name name name;
                     pr "  pbc->%s.len = xdr->%s.%s_len; \n" name name name
                   | name, FUUID -> 
                     pr "  pbc->%s.data = safe_memdup (g, xdr->%s, 32);\n" name name;
                     pr "  pbc->%s.len = 32;\n" name
                   | name, FInt32 -> 
                     pr "  pbc->%s = xdr->%s;\n" name name
                   | name, FUInt32 -> 
                     pr "  pbc->%s = xdr->%s;\n" name name
                   | name, (FInt64|FBytes) -> 
                     pr "  pbc->%s = xdr->%s;\n" name name
                   | name, FUInt64 -> 
                     pr "  pbc->%s = xdr->%s;\n" name name
                   | name, FOptPercent -> 
                     pr "  pbc->%s = xdr->%s;\n" name name
                  ) cols;
        pr "}\n";
        pr "\n";
        
        pr "void\n";
        pr "convert_guestfs_%s_protobuf_to_xdr (guestfs_h *g, \n" s_name;
        pr "                                    guestfs_int_%s *pbc,\n" s_name;
        pr "                                    struct guestfs_%s *xdr)\n" s_name;
        pr "{\n";
        List.iter (function
                   | name, FChar -> 
                     pr "  xdr->%s = pbc->%s;\n" name name
                   | name, FString -> 
                     pr "  xdr->%s = safe_strdup (g, pbc->%s);\n" name name
                   | name, FBuffer -> 
                     pr "  xdr->%s.%s_val = safe_memdup (g, pbc->%s.data, pbc->%s.len); \n" name name name name;
                     pr "  xdr->%s.%s_len = pbc->%s.len; \n" name name name
                   | name, FUUID -> 
                     pr "  xdr->%s = safe_memdup (g, pbc->%s.data, 32);\n" name name
                   | name, FInt32 -> 
                     pr "  xdr->%s = pbc->%s;\n" name name
                   | name, FUInt32 -> 
                     pr "  xdr->%s = pbc->%s;\n" name name
                   | name, (FInt64|FBytes) -> 
                     pr "  xdr->%s = pbc->%s;\n" name name
                   | name, FUInt64 -> 
                     pr "  xdr->%s = pbc->%s;\n" name name
                   | name, FOptPercent -> 
                     pr "  xdr->%s = pbc->%s;\n" name name
                  ) cols;
        pr "}\n";
        pr "\n";

        pr "void\n";
        pr "convert_guestfs_%s_list_protobuf_to_xdr (guestfs_h *g, \n" s_name;
        pr "                                    guestfs_int_%s *pbc,\n" s_name;
        pr "                                    struct guestfs_%s *xdr)\n" s_name;
        pr "{\n";
        pr "  int i;\n";
        pr "  xdr->val = safe_malloc (g, sizeof (struct guestfs_%s) * pbc->n_vals);\n" s_name;
        pr "  xdr->len = pbc->n_vals;\n";
        pr "  for (i = 0; i < pbc->n_vals; ++i) {\n";
        pr "    convert_guestfs_%s_protobuf_to_xdr (g, pbc->vals[i], &xdr->val[i]);\n" s_name;
        pr "  }\n";
        pr "}\n";

        pr "void\n";
        pr "convert_guestfs_%s_list_xdr_to_protobuf (guestfs_h *g, \n" s_name;
        pr "                                    struct guestfs_%s *xdr,\n" s_name;
        pr "                                    guestfs_int_%s *pbc)\n" s_name;
        pr "{\n";
        pr "  int i;\n";
        pr "  pbc->vals = safe_malloc (g, sizeof (guestfs_int_%s *) * xdr->len);\n" s_name;
        pr "  pbc->n_vals = xdr->len;\n";
        pr "  for (i = 0; i < xdr->len; ++i) {\n";
        pr "    pbc->vals[i] = safe_malloc (g, sizeof (guestfs_int_%s));\n" s_name;
        pr "    convert_guestfs_%s_xdr_to_protobuf (g, &xdr->val[i], pbc->vals[i]);\n" s_name;
        pr "  }\n";
        pr "}\n";

        pr "\n"
  ) structs

(*
  pr "/* Converters for function arguments and return values\n";
  pr " * from xdr to protobuf representation and vice versa.\n";
  pr "*/\n";
  pr "\n";
  List.iter (
    fun { name = shortname; style = ret, args, optargs } ->
      let name = "guestfs_" ^ shortname in

      (* Ordinary arguments and optional arguments are concatenated
       * together in the XDR args struct.  The optargs_bitmask field
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
        pr "void\n";
        pr "convert_%s_args_xdr_to_protobuf (guestfs_h *g,\n" name;
        pr "                                 %s_args *xdr,\n" name;
        pr "                                 protobuf_%s_args *pbc)\n" name;
        pr "{\n";
        List.iter (
          function
          | Pathname n | Device n | Mountable n | Dev_or_Path n
          | Mountable_or_Path n | String n
          | Key n | GUID n ->
            pr "  pbc->%s = safe_strdup (g, xdr->%s);\n" n n
          | OptString n -> 
            pr "  pbc->%s = xdr->%s ? safe_strdup (g, xdr->%s) : NULL;\n" n n n;
          | StringList n | DeviceList n -> 
            pr "  pbc->%s = safe_malloc (g, xdr->%s.%s_len * sizeof (char*));\n" n n n;
            pr "  int i;\n";
            pr "  for (i = 0; i < xdr->%s.%s_len; ++i) \n{" n n;
            pr "    pbc->n_%s = i;\n" n;
            pr "    pbc->%s[i] = xdr->%s.%s_val[i] ? safe_strdup (xdr->%s.%s_val[i]) : NULL;\n" n n n n n;
            pr "  }\n"
          | Bool n -> 
            pr "  pbc->%s = xdr->%s;\n" n n
          | Int n -> 
            pr "  pbc->%s = xdr->%s;\n" n n
          | Int64 n -> 
            pr "  pbc->%s = xdr->%s;\n" n n
          | BufferIn n ->
            pr "  pbc->%s.data = safe_memdup (g, xdr->%s.%s_val, xdr->%s.%s_len); \n" n n n n n;
            pr "  pbc->%s.len = xdr->%s.%s_len; \n" n n n
          | FileIn _ | FileOut _ | Pointer _ -> assert false
        ) args;
        pr "}\n\n"
        
        pr "void\n";
        pr "convert_%s_args_protobuf_to_xdr (guestfs_h *g,\n" name;
        pr "                                 protobuf_%s_args *pbc,\n" name;
        pr "                                 %s_args *xdr)\n" name;
        pr "{\n";
        List.iter (
          function
          | Pathname n | Device n | Mountable n | Dev_or_Path n
          | Mountable_or_Path n | String n
          | Key n | GUID n ->
            pr "  xdr->%s = safe_strdup (g, pbc->%s);\n" n n
          | OptString n -> 
            pr "  xdr->%s = pbc->%s ? safe_strdup (g, pbc->%s) : NULL;\n" n n n;
          | StringList n | DeviceList n -> 
            pr "  xdr->%s.%s_val = safe_malloc (g, pbc->%s.len * sizeof (char*));\n" n n n;
            pr "  int i;\n";
            pr "  for (i = 0; i < pbc->n_%s; ++i) \n{" n;
            pr "    xdr->%s.%s_len = i;\n" n n;
            pr "    xdr->%s.%s_val[i] = pbc->%s[i] ? safe_strdup (pbc->%s[i]) : NULL;\n" n n n n;
            pr "  }\n"
          | Bool n -> 
            pr "  xdr->%s = pbc->%s;\n" n n
          | Int n -> 
            pr "  xdr->%s = pbc->%s;\n" n n
          | Int64 n -> 
            pr "  xdr->%s = pbc->%s;\n" n n
          | BufferIn n ->
            pr "  xdr->%s.%s_val = safe_memdup (g, pbc->%s.data, pbc->%s.len);\n" n n n n;
            pr "  xdr->%s.%s_len = pbc->%s.len;\n" n n n
          | FileIn _ | FileOut _ | Pointer _ -> assert false
        ) args;
        pr "}\n\n"

      );
      
      pr "void\n";
      pr "convert_%s_ret_xdr_to_protobuf (guestfs_h *g,\n" name;
      pr "                                %s_ret"
      (match ret with
       | RErr -> ()
       | RInt n ->
           pr "struct %s_ret {\n" name;
           pr "  int %s;\n" n;
           pr "};\n\n"
       | RInt64 n ->
           pr "struct %s_ret {\n" name;
           pr "  int64_t %s;\n" n;
           pr "};\n\n"
       | RBool n ->
           pr "struct %s_ret {\n" name;
           pr "  bool %s;\n" n;
           pr "};\n\n"
       | RConstString _ | RConstOptString _ ->
           failwithf "RConstString|RConstOptString cannot be used by daemon functions"
       | RString n ->
           pr "struct %s_ret {\n" name;
           pr "  string %s<>;\n" n;
           pr "};\n\n"
       | RStringList n ->
           pr "struct %s_ret {\n" name;
           pr "  guestfs_str %s<>;\n" n;
           pr "};\n\n"
       | RStruct (n, typ) ->
           pr "struct %s_ret {\n" name;
           pr "  guestfs_int_%s %s;\n" typ n;
           pr "};\n\n"
       | RStructList (n, typ) ->
           pr "struct %s_ret {\n" name;
           pr "  guestfs_int_%s_list %s;\n" typ n;
           pr "};\n\n"
       | RHashtable n ->
           pr "struct %s_ret {\n" name;
           pr "  guestfs_str %s<>;\n" n;
           pr "};\n\n"
       | RBufferOut n ->
           pr "struct %s_ret {\n" name;
           pr "  opaque %s<>;\n" n;
           pr "};\n\n"
      );
  ) daemon_functions;

  pr "/* Table of procedure numbers. */\n";
  pr "enum guestfs_procedure {\n";
  let rec loop = function
    | [] -> ()
    | { proc_nr = None } :: _ -> assert false
    | { name = shortname; proc_nr = Some proc_nr } :: [] ->
      pr "  GUESTFS_PROC_%s = %d\n" (String.uppercase shortname) proc_nr
    | { name = shortname; proc_nr = Some proc_nr } :: rest ->
      pr "  GUESTFS_PROC_%s = %d,\n" (String.uppercase shortname) proc_nr;
      loop rest
  in
  loop daemon_functions;
  pr "};\n";
  pr "\n";

  pr "const GUESTFS_MAX_PROC_NR = %d;\n" max_proc_nr;
  pr "\n";

  pr "/* The remote procedure call protocol. */\n";
  pr "\n";

  (* Having to choose a maximum message size is annoying for several
   * reasons (it limits what we can do in the API), but it (a) makes
   * the protocol a lot simpler, and (b) provides a bound on the size
   * of the daemon which operates in limited memory space.
   *)
  pr "const GUESTFS_MESSAGE_MAX = %d;\n" (4 * 1024 * 1024);
  pr "\n";

  (* Message header, etc. *)
  pr "\
const GUESTFS_PROGRAM = 0x2000F5F5;
const GUESTFS_PROTOCOL_VERSION = 4;

/* These constants must be larger than any possible message length. */
const GUESTFS_LAUNCH_FLAG = 0xf5f55ff5;
const GUESTFS_CANCEL_FLAG = 0xffffeeee;
const GUESTFS_PROGRESS_FLAG = 0xffff5555;

enum guestfs_message_direction {
  GUESTFS_DIRECTION_CALL = 0,        /* client -> daemon */
  GUESTFS_DIRECTION_REPLY = 1        /* daemon -> client */
};

enum guestfs_message_status {
  GUESTFS_STATUS_OK = 0,
  GUESTFS_STATUS_ERROR = 1
};

";

  pr "const GUESTFS_ERROR_LEN = %d;\n" (64 * 1024);
  pr "\n";

  pr "\
struct guestfs_message_error {
  string errno_string<32>;           /* errno eg. \"EINVAL\", empty string
                                        if errno not available */
  string error_message<GUESTFS_ERROR_LEN>;
};

struct guestfs_message_header {
  unsigned prog;                     /* GUESTFS_PROGRAM */
  unsigned vers;                     /* GUESTFS_PROTOCOL_VERSION */
  guestfs_procedure proc;            /* GUESTFS_PROC_x */
  guestfs_message_direction direction;
  unsigned serial;                   /* message serial number */
  uint64_t progress_hint;            /* upload hint for progress bar */
  uint64_t optargs_bitmask;          /* bitmask for optional args */
  guestfs_message_status status;
};

const GUESTFS_MAX_CHUNK_SIZE = 8192;

struct guestfs_chunk {
  int cancel;			     /* if non-zero, transfer is cancelled */
  /* data size is 0 bytes if the transfer has finished successfully */
  opaque data<GUESTFS_MAX_CHUNK_SIZE>;
};

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
struct guestfs_progress {
  guestfs_procedure proc;            /* @0:  GUESTFS_PROC_x */
  unsigned serial;                   /* @4:  message serial number */
  uint64_t position;                 /* @8:  0 <= position <= total */
  uint64_t total;                    /* @16: total size of operation */
                                     /* @24: size of structure */
};
"

*)
