#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t process_string(char *str);

int main(void) {
    size_t (*fpstrlen)(char *);
    char *pstr[] = {
        "The art of C programming",
        "C++ is a good choice for OOP",
        "Functional programming is beautiful and Lisp is a good think",
        "AWK was initially developer in 1977 ...",
        "...by Aho, Weinberger and Kernighan",
        "UNIX is an ideal development environment"
    };

    fpstrlen = process_string;

    for (int i = 0; i < (sizeof(pstr)/sizeof(pstr[0])); i++)
        printf("The length of \"%s\" is: %d\n", pstr[i], fpstrlen(pstr[i]));
    
    return(EXIT_SUCCESS);
}

size_t process_string(char *str) {
    size_t i=0;

    while (*str++)
        i++;

    return i;
}
