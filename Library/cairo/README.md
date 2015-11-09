## Cairo is a 2D graphics library

First of all install the cairo library on GNU/Linux Debian-like systems
`libcairo2-dev`, then add the proper header: `#include <cairo/cairo.h>`

### How to compile 

$ clang main.c -std=c11 -Wall -pedantic -lcairo
$ gcc main.c   -std=c11 -Wall -pedantic -lcairo
