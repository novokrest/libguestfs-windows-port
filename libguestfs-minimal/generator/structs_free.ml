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
let generate_structs_free_header () =
  generate_header ~emacs_mode:"c" CStyle LGPLv2plus;

  pr "/* This file defines destructors for all guestfs internal structures */\n";
  pr "\n";
  pr "#include \"xdr.h\"";
  pr "\n";
  List.iter (
    fun { s_name = typ; s_cols = cols } ->
        pr "void guestfs_int_free_%s (guestfs_int_%s *s);\n" typ typ;
        pr "\n";
        pr "void guestfs_int_free_%s_list (guestfs_int_%s_list *s);\n" typ typ;
        pr "\n"
  ) structs

let generate_structs_free () =
  generate_header ~emacs_mode:"c" CStyle LGPLv2plus;

  pr "/* This file defines destructors for all guestfs internal structures */\n";
  pr "\n";
  pr "#include \"xdr.h\"";
  pr "\n";
  List.iter (
    fun { s_name = typ; s_cols = cols } ->
        pr "void\n";
        pr "guestfs_int_free_%s (guestfs_int_%s *s)\n" typ typ;
        pr "{\n";
        List.iter (
          function
          | name, FString -> pr "  free (s->%s);\n" name
          | name, FBuffer -> pr "  free (s->%s.%s_val);\n" name name
          | _, FChar
          | _, FUUID
          | _, FUInt32
          | _, FInt32
          | _, FUInt64
          | _, FBytes
          | _, FInt64
          | _, FOptPercent -> ()
        ) cols;
        pr "}\n";
        pr "\n";
        pr "void\n";
        pr "guestfs_int_free_%s_list (guestfs_int_%s_list *s)\n" typ typ;
        pr "{\n";
        pr "  int i;\n";
        pr "  for (i = 0; i < s->guestfs_int_%s_list_len; ++i) {\n" typ;
        pr "    guestfs_int_free_%s (&s->guestfs_int_%s_list_val[i]);\n" typ typ;
        pr "  }\n";
        pr "  free (s->guestfs_int_%s_list_val);\n" typ;
        pr "}\n";
        pr "\n"
  ) structs

