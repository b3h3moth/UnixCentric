#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio_ext.h>

/* Lo scopo del programma e' di scartare l'output pendente mediante
l'utilizzo della funzione __fpurge().

La funzione __fpurge() non e' ne' standard ne' portabile, e' stata introdotta
in Solaris, presente nella libreria glibc.*/

int main(void) {

    /* A differenza della funzione fflush() che forza la scrittura del buffer
    cache, la funzione __fpurge() pulisce il buffer dello stream fornito.

    Nel caso specifico sara' scartato tutto l'output non ancora scritto, per
    cui la funzione printf() non produrra' alcunche' */

    printf("Get-up stand-up, stand-up for your rights, by: ");
    __fpurge(stdout);
    write(1, "Bob Marley.\n", 12);

    return(EXIT_SUCCESS);
}
