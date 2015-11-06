#include <stdio.h>
#include <stdlib.h>

#define MIN(type)                 \
type type##_min(type x, type y) { \
    return x < y ? x : y;         \
}                                 

/* Le definizioni di macro possono contenere due operatori speciali:
- '#'  converte un argomento in una stringa, da cui 'stringization';
- '##' compatta/incolla assieme due token, da cui 'token pasting';
