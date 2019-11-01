open Printf

type elem = Range of int * int | Int of int

let rec convert acc (nums_list : int list) : elem list =
  let rec loop start nums : int * (int list) =
    match nums with
      [] -> (start, [])
    | n :: ns ->
        if n = start + 1 then
          loop (start + 1) ns
        else
          (start, nums)
  in
  match nums_list with
    [] -> List.rev acc
  | n :: ns ->
      (match loop n ns with
         (k, l) ->
           if k = n then
             convert ((Int n) :: acc) ns
           else
             convert ((Range (n, k)) :: acc) l)

let rec print_elems elems =
  match elems with
    [] -> printf "\n"
  | e :: es ->
      (match e with
         Int n ->
           printf "%d " n;
           print_elems es
       | Range (n, k) ->
           if k - n > 1 then
             printf "%d-%d " n k
           else
             printf "%d %d " n k;
           print_elems es)

let main () =
  let n = read_int () in
  let nums_str = read_line () in
  let str_list = Str.split (Str.regexp " ") nums_str in
  let nums_list = List.fast_sort compare (List.map int_of_string str_list) in
  let elem_list = convert [] nums_list in
  print_elems elem_list

let _ = main ()
