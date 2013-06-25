#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* Un filtro UNIX e' un processo che legge dallo standard input e scrive sullo
standard output, di solito i filtri sono connessi linearmente mediante una 
shell pipeline; pertanto se lo stesso processo legge dallo standard input e 
scrive sullo standard output si sta parlando di coprocesso. */

/* Un processo crea due pipe, una e' lo standard input del coprocesso, l'altra
e' lo standard output del coprocesso; il programma e' un coprocesso che legge
due numeri dal proprio standard input, si sommano, e la somma viene scritta nel
proprio standard output. */

int main(void) {
    return(EXIT_SUCCESS);
}
