#include <stdio.h>
#include <stdlib.h>

#define AP_SIZE ( sizeof(strings) / sizeof(strings[0]) )

int main(void) {
    char **first, **last;

    char *strings[] = {
        "aaabbbcccbbbaaa",
        "abababbababa",
        "qwertyaggagaagytrewq",
        "assaassaassasa",
    };

    first = strings;

    for (int i=0; i<AP_SIZE; i++) {
    }

    return(EXIT_SUCCESS);
}
