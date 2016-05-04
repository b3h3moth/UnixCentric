#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *allocmem(char *buf, int size);

int main(void) {
    char def_string[] = "C language programming";
    char *buffer = NULL;
    int size = strlen(def_string)+1;

    buffer = allocmem(buffer, size);
    strcpy(buffer, def_string);

    /* Imposta il null character finale. */
    *(buffer + --size) = '\0';  // Equivalente a buffer[--size]

    printf("strlen(default): %d - %s\n", size, def_string);
    printf("   strlen(copy): %d - %s\n", strlen(buffer), buffer);
    
    return(EXIT_SUCCESS);
}

/* La funzione allocmem() ritorna l'indirizzo di memoria di grandezza utile 
a contenere esattamente un vettore di caratteri 'buf' di dimensioni 'size'. */
char *allocmem(char *buf, int size) {
    return buf = calloc(size,  sizeof(char));
}
