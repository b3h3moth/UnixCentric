#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *allocMemory(char *buf, int size);

int main(void) {
    char def_string[] = "C language programming";
    char *buffer;
    int size = strlen(def_string)+1;

    buffer = allocMemory(buffer, size);
    strcpy(buffer, def_string);

    /* Si imposta il carattere di fine stringa */
    buffer[--size] = '\0';

    printf("strlen(default string): %d - %s\n", size, def_string);
    printf("    strlen(new string): %d - %s\n", strlen(buffer), buffer);
    
    return(EXIT_SUCCESS);
}

/* La funzione allocMemory() ritorna l'indirizzo di memoria di grandezza utile 
a contenere esattamente un vettore di caratteri 'buf' di 'size' dimensioni */
char *allocMemory(char *buf, int size)
{
    return buf = calloc(size,  sizeof(char));
}
