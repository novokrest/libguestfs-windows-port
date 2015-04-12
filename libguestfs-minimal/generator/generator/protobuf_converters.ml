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
 
let generate_protobuf_converters_header () = 
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
        pr "                                    guestfs_int_%s *xdr,\n" s_name;
        pr "                                    guestfs_protobuf_int_%s *pbc);\n" s_name;

        pr "\n";
        
        pr "void\n";
        pr "convert_guestfs_%s_list_xdr_to_protobuf (guestfs_h *g, \n" s_name;
        pr "                                         guestfs_protobuf_int_%s_list *xdr,\n" s_name;
        pr "                                         guestfs_int_%s_list *pbc);\n" s_name;

        pr "\n";
        
        pr "void\n";
        pr "convert_guestfs_%s_protobuf_to_xdr (guestfs_h *g, \n" s_name;
        pr "                                    guestfs_protobuf_int_%s *pbc,\n" s_name;
        pr "                                    guestfs_int_%s *xdr);\n" s_name;
        
        pr "\n";
        
        pr "void\n";
        pr "convert_guestfs_%s_list_protobuf_to_xdr (guestfs_h *g, \n" s_name;
        pr "                                         guestfs_protobuf_int_%s_list *pbc,\n" s_name;
        pr "                                         guestfs_int_%s_list *xdr);\n" s_name;
        
        pr "\n"

  ) structs;
  
    List.iter (
    fun { name = name; style = ret, args, optargs } ->

      let args_passed_to_daemon = args @ args_of_optargs optargs in
      let args_passed_to_daemon =
        List.filter (function FileIn _ | FileOut _ -> false | _ -> true)
          args_passed_to_daemon in
      (match args_passed_to_daemon with
      | [] -> ()
      | args ->
        pr "void\n";
        pr "convert_%s_args_xdr_to_protobuf (guestfs_h *g,\n" name;
        pr "                                 guestfs_%s_args *xdr,\n" name;
        pr "                                 guestfs_protobuf_%s_args *pbc);\n" name;

        pr "void\n";
        pr "convert_%s_args_protobuf_to_xdr (guestfs_h *g,\n" name;
        pr "                                 protobuf_%s_args *pbc,\n" name;
        pr "                                 %s_args *xdr);\n" name;
      );
      
      pr "void\n";
      pr "convert_%s_ret_xdr_to_protobuf (guestfs_h *g,\n" name;
      pr "                                guestfs_%s_ret *xdr,\n" name;
      pr "                                guestfs_protobuf_%s_ret *pbc)\n" name;
      
      pr "void\n";
      pr "convert_%s_ret_protobuf_to_xdr (guestfs_h *g,\n" name;
      pr "                                guestfs_protobuf_%s_ret *pbc,\n" name;
      pr "                                guestfs_%s_ret *xdr);\n" name;

  ) daemon_functions;
  
  pr "#endif /* GUESTFS_PROTOCOL_CONVERTERS_H_ */"
  
let generate_protobuf_converters () =
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
        pr "                                    guestfs_int_%s *xdr,\n" s_name;
        pr "                                    guestfs_protobuf_int_%s *pbc)\n" s_name;
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
        pr "                                    guestfs_protobuf_int_%s *pbc,\n" s_name;
        pr "                                    guestfs_int_%s *xdr)\n" s_name;
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
        pr "                                         guestfs_protobuf_int_%s_list *pbc,\n" s_name;
        pr "                                         guestfs_int_%s_list *xdr)\n" s_name;
        pr "{\n";
        pr "  int i;\n";
        pr "  xdr->%s_val = safe_malloc (g, sizeof (guestfs_int_%s) * pbc->n_vals);\n" s_name s_name;
        pr "  xdr->%s_len = pbc->n_vals;\n" s_name;
        pr "  for (i = 0; i < pbc->n_vals; ++i) {\n";
        pr "    convert_guestfs_%s_protobuf_to_xdr (g, pbc->vals[i], &xdr->%s_val[i]);\n" s_name s_name;
        pr "  }\n";
        pr "}\n";

        pr "void\n";
        pr "convert_guestfs_%s_list_xdr_to_protobuf (guestfs_h *g, \n" s_name;
        pr "                                         guestfs_int_%s_list *xdr,\n" s_name;
        pr "                                         guestfs_protobuf_int_%s_list *pbc)\n" s_name;
        pr "{\n";
        pr "  int i;\n";
        pr "  pbc->vals = safe_malloc (g, sizeof (guestfs_protobuf_int_%s *) * xdr->%s_len);\n" s_name s_name;
        pr "  pbc->n_vals = xdr->len;\n";
        pr "  for (i = 0; i < xdr->len; ++i) {\n";
        pr "    pbc->vals[i] = safe_malloc (g, sizeof (guestfs_protobuf_int_%s));\n" s_name;
        pr "    convert_guestfs_%s_xdr_to_protobuf (g, &xdr->%s_val[i], pbc->vals[i]);\n" s_name s_name;
        pr "  }\n";
        pr "}\n";

        pr "\n"
  ) structs;

  pr "/* Converters for function arguments and return values\n";
  pr " * from xdr to protobuf representation and vice versa.\n";
  pr "*/\n";
  pr "\n";
  List.iter (
    fun { name = name; style = ret, args, optargs } ->

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
        pr "                                 guestfs_%s_args *xdr,\n" name;
        pr "                                 guestfs_protobuf_%s_args *pbc)\n" name;
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
        pr "}\n\n";
        
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
      pr "                                guestfs_%s_ret *xdr,\n" name;
      pr "                                guestfs_protobuf_%s_ret *pbc)\n" name;
      pr "{\n";
      (match ret with
       | RErr -> ()
       | RInt n | RInt64 n | RBool n ->
         pr "  pbc->%s = xdr->%s;\n" n n 
       | RConstString _ | RConstOptString _ ->
           failwithf "RConstString|RConstOptString cannot be used by daemon functions"
       | RString n ->
         pr "  pbc->%s = safe_strdup (g, xdr->%s);\n" n n
       | RStringList n | RHashtable n ->
         pr "  pbc->%s = safe_malloc (g, xdr->%s.%s_len * sizeof (char*));\n" n n n;
         pr "  int i;\n";
         pr "  for (i = 0; i < xdr->%s.%s_len; ++i) \n{" n n;
         pr "    pbc->n_%s = i;\n" n;
         pr "    pbc->%s[i] = xdr->%s.%s_val[i] ? safe_strdup (xdr->%s.%s_val[i]) : NULL;\n" n n n n n;
         pr "  }\n"
       | RStruct (n, typ) ->
         pr "  pbc->%s = safe_malloc (g, sizeof (guestfs_protobuf_int_%s));\n" n typ;
         pr "  convert_guestfs_int_%s_xdr_to_protobuf (g, &xdr->%s, pbc->%s);\n" typ n n
       | RStructList (n, typ) ->
         pr "  pbc->%s = safe_malloc (g, sizeof (guestfs_protobuf_int_%s_list));\n" n typ;
         pr "  convert_guestfs_int_%s_list_xdr_to_protobuf (g, &xdr->%s, pbc->%s);\n" typ n n
       | RBufferOut n ->
         pr "  pbc->%s.data = safe_memdup (g, xdr->%s.%s_val, xdr->%s.%s_len);\n" n n n n n;
         pr "  pbc->%s.len = xdr->%s.%s_len;\n" n n n
      );
      pr "}\n\n";
      
      pr "void\n";
      pr "convert_%s_ret_protobuf_to_xdr (guestfs_h *g,\n" name;
      pr "                                guestfs_protobuf_%s_ret *pbc,\n" name;
      pr "                                guestfs_%s_ret *xdr)\n" name;
      pr "{\n";
      (match ret with
       | RErr -> ()
       | RInt n | RInt64 n | RBool n ->
         pr "  xdr->%s = pbc->%s;\n" n n
       | RConstString _ | RConstOptString _ ->
           failwithf "RConstString|RConstOptString cannot be used by daemon functions"
       | RString n ->
         pr "  xdr->%s = safe_strdup (g, pbc->%s);\n" n n
       | RStringList n | RHashtable n ->
         pr "  xdr->%s.%s_val = safe_malloc (g, pbc->%s.len * sizeof (char*));\n" n n n;
         pr "  int i;\n";
         pr "  for (i = 0; i < pbc->n_%s; ++i) \n{" n;
         pr "    xdr->%s.%s_len = i;\n" n n;
         pr "    xdr->%s.%s_val[i] = pbc->%s[i] ? safe_strdup (pbc->%s[i]) : NULL;\n" n n n n;
         pr "  }\n"
       | RStruct (n, typ) ->
         pr "  convert_guestfs_int_%s_protobuf_to_xdr (g, pbc->%s, &xdr->%s);\n" typ n n
       | RStructList (n, typ) ->
         pr "  convert_guestfs_int_%s_list_protobuf_to_xdr (g, pbc->%s, &xdr->%s);\n" typ n n
       | RBufferOut n ->
         pr "  xdr->%s.%s_val = safe_memdup (g, pbc->%s.data, pbc->%s.len);\n" n n n n;
         pr "  xdr->%s.%s_len = pbc->%s.len;\n" n n n
      );
      pr "}\n\n";

  ) daemon_functions
