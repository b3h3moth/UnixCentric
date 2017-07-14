#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOC_SIZE 100     /* Spazio disponibile */

static char allocbuf[ALLOC_SIZE];   /* vettore di memoria */
static char *palloc = allocbuf;     /* primo elemento libero */

char *alloc(int n);
void afree(char *p);

int main(int argc, char *argv[]) {
    int size = 50;
    char *str1 = alloc(size);
    char *str2 = alloc(size);

    strlcpy(str1, "abcdefghijklmnoprstuvwzx abcdefghijklmnoprstuvwzx", size);
    strlcpy(str2, "1234567890 1234567890 1234567890 1234567890 12345", size);

    /* 
    E' sufficiente un byte per superare il limite 
    char *str3 = alloc(1);
    strlcpy(str3, "x", 1); 
    */

    printf("%s\n%s\n", str1, str2);

    return(EXIT_SUCCESS);
}

/* La funzione alloc() restituisce un puntatore a n caratteri */
char *alloc(int n) {
    if (allocbuf + ALLOC_SIZE - palloc >= n) {
        palloc += n;
        return palloc -n;
    } else
        return 0;
}

/* Libera la memoria puntata da p */
void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOC_SIZE)
        palloc = p;
}
