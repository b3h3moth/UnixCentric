#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basic_malloc.h"
#include "xmalloc.h"
#include "zmalloc.h"

int main(void) {
    const char *title = "The Unix Programming Environment";
    const unsigned int size = strlen(title);
    char *ptr;

    // malloc(a) testing function
    // Alloca 'size' byte sullo heap, dopodiche' copia e stampa la stringa
    ptr = basic_malloc(size);
    strcpy(ptr, title);
    printf("%s\n", ptr);

    /* Con la prima funzione per l'allocazione della memoria malloca(), non
    puo' essere usata free() per liberare la memoria, per cui si utilizzera'
    un semplice puntatore a NULL, ma non sara' di certo sufficiente in questo
    caso. */
    ptr = NULL;

    // my_malloc()
    char *ptr2;
    ptr2 = my_malloc(size);
    strcpy(ptr2, title);
    printf("%s\n", ptr2);
    my_free(ptr2);
    ptr2 = NULL;

    return(EXIT_SUCCESS);
}
