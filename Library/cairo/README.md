## Cairo is a 2D graphics library

First of all install the cairo library, libcairo2-dev, then add the proper
header to file #include <cairo/cairo.h>

### How to compile 

$ clang main.c -std=c11 -Wall -pedantic -lcairo
$ gcc main.c   -std=c11 -Wall -pedantic -lcairo
