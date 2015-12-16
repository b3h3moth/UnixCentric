The MagicWand C API is the interface between C and ImageMagick library. On 
Debian GNU/Linux system and its derivatives the .deb epackage to install is
`libmagickwand-6.q16-dev`.

### How to compile

$ ``$ gcc   -std=c11 -Wall -pedantic main.c `pkg-config --cflags --libs MagickWand```
$ ``$ clang -std=c11 -Wall -pedantic main.c `pkg-config --cflags --libs MagickWand```
