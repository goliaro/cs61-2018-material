Lecture 1
=========

Quicksort
---------

We investigated a number of different quicksort implementations as
systems programs.

Quicksort on Wikipedia: https://en.wikipedia.org/wiki/Quicksort

* `qs.ml`: An OCaml quicksort function.

* `qs0.c` through `qs3.c`: List-based quicksorts (like OCaml).
  * `ilist.h`: A little library for handling singly-linked lists of
    integers.
  * `testqs-list.c`: The test driver.

* `qs4.c` through `qs6.c`: Array-based quicksorts.
  * `testqs-array.c`: The test driver.

* `qs7.c`: Standard library quicksort (array-based).

Type `make` to build programs `testqs0` through `testqs7`. Options for
these programs are:

* `./testqsX -r [N]`: The array contains `N` random ints. Default `N`
  is 6.
* `./testqsX -u [N]`: The array is initially sorted.
* `./testqsX -d [N]`: The array is initially reverse-sorted.
* `./testqsX -m [N]`: The array contains the numbers 1,...,`N` in a
  magic evil order.

Executions to try:

* `./testqs0 -r 10`
* `./testqs0 -r 10000000`
* `make SANITIZE=1; ./testqs0 -r 10`
* `./testqs5 -m 100000`

Try `time ./testqsX` to see how long an execution takes.

Further reading: "Implementing Quicksort Programs", Robert Sedgewick,
Communications of the ACM 21(10), October 1978;
http://www.csie.ntu.edu.tw/~b93076/p847-sedgewick.pdf

"Engineering a Sort Function", Jon L. Bentley and M. Douglas McIlroy,
Software---Practice and Experience 23(11), November 1993;
http://www.skidmore.edu/~meckmann/2009Spring/cs206/papers/spe862jb.pdf


Add
---

Run `./add 2 2` to add 2 and 2.

Run `./addin FILE OFFSET A B` to add `A` and `B`, using the “add function”
located in `FILE` at byte `OFFSET`. For instance, try `./addin addf.o 64 2 2`.

Use `objdump -S addf.o` to look at the instructions in `addf.o`.
