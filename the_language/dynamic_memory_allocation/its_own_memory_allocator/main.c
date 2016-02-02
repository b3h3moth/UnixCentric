#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_malloca.h"

int main(void) {
    static const char *title = "The Unix Programming Environment";
    static const unsigned int size = sizeof(title);
    char *ptr;

    /* Alloca 'size' byte sullo heap, dopodiche' copia e stampa la stringa */
    ptr = malloca(size);
    strcpy(ptr, title);
    printf("%s\n", ptr);

    return(EXIT_SUCCESS);
}
