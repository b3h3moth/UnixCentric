# Simple DirectMedia Layer (SDL)

E' una libreria multimediale cross-platform di sviluppo che fornisce un accesso
low-level all'hardware grafico via OpenGL e Direct3D, ad audio, keyboard, 
mouse, joystick, cdrom e inoltre fornisce supporto ai thread e alla gestione
del tempo.

> E' ampiamente utilizzata principalmente per la scrittura di video games.

## Which API version we are using

Version: 2.0.x

## How to Compile SDL programs

With sdl2-config tool:

`gcc program.c -std=c11 (or c99) -Wall -pedantic `sdl2-config --cflags --libs``

`clang program.c -std=c11 (or c99) -Wall -pedantic `sdl2-config --cflags --libs``

Linking the library directly:

`gcc -std=c11 (or c99) -Wall -pedantic -lSDL2 program.c`

`clang -std=c11 (or c99) -Wall -pedantic -lSDL2 program.c`

## How to get the library

[dowanload](https://libsdl.org) source code from the main site.
