## Cairo is a 2D graphics library

First of all install the cairo library on GNU/Linux:
- on Debian and its derivatives:
`# apt- get install libcairo2-dev`

The proper header is: `#include <cairo/cairo.h>`

### How to compile 

$ clang main.c -std=c11 -Wall -pedantic -lcairo
$ gcc main.c   -std=c11 -Wall -pedantic -lcairo
