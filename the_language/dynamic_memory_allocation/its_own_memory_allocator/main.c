#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_malloca.h"

int main(void) {
    char *title = "The Unix Programming Environment";
    unsigned int size = sizeof(title);
    char *ptr;

    ptr = malloca(size);

    strcpy(ptr, title);

    printf(ptr);

    return(EXIT_SUCCESS);
}
