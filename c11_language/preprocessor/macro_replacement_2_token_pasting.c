#include <stdio.h>
#include <stdlib.h>

#define MAIN(type) i ## n ##t m ##ain(type)

MAIN(void)

    printf("It works\n");

    exit(EXIT_SUCCESS);
}


/* Le definizioni di macro possono contenere due operatori speciali:
- '#'  converte un argomento in una stringa, da cui 'stringization';
- '##' compatta/incolla assieme due token, da cui 'token pasting'; */
