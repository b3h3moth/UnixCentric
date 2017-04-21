## The Art of Writing (C)ode in the UNIX Environment

The purpose of this project is to create a repository with a lot of source
code well documented, it is totally focused on the beautiful art of writing 
UNIX programs in C, c11 mainly.

### How to compile programs

`$gcc   -std=c11 -Wall -pedantic source.c`
`$clang -std=c11 -Wall -pedantic source.c`

Sometimes we need a macro like _BSD_SOURCE or _GNU_SOURCE to compile.

A list of compilers and Unix-like Operating systems used:

* OpenBSD (-current) on PowerPC Architecture (32 bit, big-endian)
  * gcc 4.2.1

* Debian GNU/Linux (testing) (64 bit, little endian)
  * gcc (Debian 6.3.0-12) 6.3.0
  * clang version 3.8.1-18

* OpenBSD (-current) (64 bit, little endian)
  * gcc 4.2.1
  * clang
