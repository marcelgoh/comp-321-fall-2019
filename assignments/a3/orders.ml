open Printf
open Str

type answer = Impossible | Ambiguous | Ptr of int

let rec fill_arr arr idx costs max : unit =
  let rec iter c i =
    if i > max then
      () (* only build array as required (not always 30000 *)
    else (
      match arr.(i) with
        Impossible -> iter c (i + 1)
      | Ambiguous ->
          (* ambiguity propagates up the array *)
          arr.(i + c) <- Ambiguous;
          iter c (i + 1)
      | Ptr _ ->
          (match arr.(i + c) with
             Impossible ->
               (* later we can follow the pointers back to 0 *)
               arr.(i + c) <- Ptr idx
           | _ ->
               (* multiple ways to reach a certain value *)
               arr.(i + c) <- Ambiguous);
          iter c (i + 1)
    )
  in
  match costs with
    [] -> ()
  | c :: cs ->
      iter c 0;
      fill_arr arr (idx + 1) cs max

let str_of_order (arr : answer array) cost_arr order =
  (* builds the list to print if possible,
   * returns None if ambiguous
   *)
  let rec build_list acc (o : int) : (int list) option =
    let back_ptr = arr.(o) in
    match back_ptr with
      Ptr 0 -> Some (List.fast_sort compare acc)
    | Ptr p ->
        let sub = cost_arr.(p - 1) in
        build_list (p :: acc) (o - sub)
    | _ -> None (* ambiguous *)
  in
  match arr.(order) with
    Impossible -> "Impossible\n"
  | Ambiguous -> "Ambiguous\n"
  | Ptr _ ->
      (match build_list [] order with
         None -> "Ambiguous\n"
       | Some ns ->
           (String.concat " " (List.map string_of_int ns)) ^ "\n")

(* get max positive integer in non-empty list *)
let rec max_of_list nums =
  match nums with
    [] -> -1
  | n :: ns ->
      let m = max_of_list ns in
      if n > m then n else m

(* print array for debugging *)
let print_arr arr max =
  for i = 0 to max do
    match arr.(i) with
      Impossible ->
        printf "%d: Impossible\n" i
    | Ambiguous ->
        printf "%d: Ambiguous\n" i
    | Ptr p ->
        printf "%d: Ptr %d\n" i p
  done

(* all the I/O and stuff *)
let main () =
  let _ = read_int () in
  let cost_str = read_line () in
  let costs = List.map int_of_string (Str.split (Str.regexp " ") cost_str) in
  let cost_arr = Array.of_list costs in
  let _ = read_int () in
  let order_str = read_line () in
  let orders = List.map int_of_string (Str.split (Str.regexp " ") order_str) in
  let arr : answer array = Array.make 30002 Impossible in
  arr.(0) <- Ptr 0;
  let max_order = max_of_list orders in
  fill_arr arr 1 costs max_order;
(*   print_arr arr max_order; *)
  List.iter (fun o -> printf "%s" (str_of_order arr cost_arr o)) orders;
  exit 0

let () = main ()
