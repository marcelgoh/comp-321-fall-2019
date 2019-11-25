open Printf
open Str

(* fill the distances matrix *)
let rec fill_dists grid dist m n queue =
  if Queue.is_empty queue then
    ()  (* base case: exit if queue empty *)
  else
    let (x, y) = Queue.take queue in
    let step_size = grid.(x).(y) in
    if step_size = 0 then
      fill_dists grid dist m n queue
    else
      let curr_dist = dist.(x).(y) in
      (* for each of the four cardinal directions, check if we need to update matrix,
       * and add a new pair to queue if so
       *)
      if x - step_size >= 0 &&
         (dist.(x - step_size).(y) > curr_dist + 1 || dist.(x - step_size).(y) = (-1))
      then (
        dist.(x - step_size).(y) <- curr_dist + 1;
        Queue.add (x - step_size, y) queue
      );
      if y - step_size >= 0 &&
         (dist.(x).(y - step_size) > curr_dist + 1 || dist.(x).(y - step_size) = (-1))
      then (
        dist.(x).(y - step_size) <- curr_dist + 1;
        Queue.add (x, y - step_size) queue
      );
      if x + step_size < m &&
         (dist.(x + step_size).(y) > curr_dist + 1 || dist.(x + step_size).(y) = (-1))
      then (
        dist.(x + step_size).(y) <- curr_dist + 1;
        Queue.add (x + step_size, y) queue
      );
      if y + step_size < n &&
         (dist.(x).(y + step_size) > curr_dist + 1 || dist.(x).(y + step_size) = (-1))
      then (
        dist.(x).(y + step_size) <- curr_dist + 1;
        Queue.add (x, y + step_size) queue
      );
      fill_dists grid dist m n queue

let main () =
  (* get input *)
  let nums_str = read_line () in
  let nums = List.map int_of_string (Str.split (Str.regexp " ") nums_str) in
  let m = List.hd nums in
  let n = List.hd (List.tl nums) in
  let grid = Array.make_matrix m n 0 in
  for i = 0 to m - 1 do
    let s = read_line () in
    for j = 0 to n - 1 do
      grid.(i).(j) <- int_of_char s.[j] - (int_of_char '0')
    done;
  done;
  let dist = Array.make_matrix m n (-1) in
  let queue = Queue.create () in
  Queue.add (0,0) queue;
  dist.(0).(0) <- 0;
  fill_dists grid dist m n queue;
  printf "%d\n" dist.(m-1).(n-1)

let _ = main ()
