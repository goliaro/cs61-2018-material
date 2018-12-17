Lecture 2
=========

Objdump
-------

We used the `objdump` utility today to look at compiled
code. `objdump` can produce many different kinds of output, depending
on the options you give it.  Some common ones:

* `objdump -s FILE.o` (or `objdump -s EXECUTABLEFILE`): Print the
  assembly instructions in the object file or executable.
* `objdump -S FILE.o`: Print the instructions, interleaved with the source
  files that generated those instructions. Only works if the object file or
  executable was compiled with debugging support (which all your files will
  be).

Since `objdump` usually generates a lot of output, it’s useful to send
its output to a “pager” program, so you can scroll through that
output. We prefer `less`:

    $ objdump -s FILE.o | less

Within `less`, type spacebar to go forward a screen, `b` to go back a
screen, and `q` to quit.

Many command line programs have useful help available


Undefined behavior
------------------

Use the `ubexplore` program to explore undefined behavior. Look at
`ubexplore.c`, then run `./ubexplore.opt` and `./ubexplore.noopt`,
with and without sanitization, with different arguments.


Data representation
-------------------

Use the `mexplore` program to explore data representation and
distinguish storage lifetimes.
