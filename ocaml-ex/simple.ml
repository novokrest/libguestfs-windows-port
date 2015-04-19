open Unix
open Printf

let chan = ref Pervasives.stdout

let pr fs =
  ksprintf
    (fun str ->
       output_string !chan str
    ) fs

let test () =
  let lines = ref 0 in
  pr "start\n";
  List.iteri(fun ind col ->
              match col with 
               | str, c -> pr "%s: %d\n" str (ind + 1);
                 lines := !lines +1
            ) ["A",1; "B",2];
  pr "end\n"
  
let () = 
  test ()
