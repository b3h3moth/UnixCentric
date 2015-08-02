#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void printout(int num, ...);

int main(int argc, char *argv[]) {

    return(EXIT_SUCCESS);
}

void printout(int num, ...) {
    va_list ap;

    va_start(ap, num);

    if (num >= 1)
        printf("%s", va_arg(ap, char *));
    if (num >= 2)
        printf("%s", va_arg(ap, char *));
    if (num >= 3)
        printf("%d", va_arg(ap, int));
    printf("\n");

    va_end(ap);
}

