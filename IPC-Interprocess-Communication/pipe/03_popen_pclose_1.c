#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define PAGER "${PAGER:-less}"
#define MAX_BUF 512

/* Il lavoro fatto dalla funzione pipe() viene svolto interamente dalle funzioni
popen() e pclose().


HEADER    : <stdio.h>
PROTOTYPE : FILE *popen(const char *cmdstring, const char *type);
SEMANTICS : La funzione popen() apre una pipe, crea un nuovo processo mediante
            una fork ed esegue 'cmdstring' su una exec e ritorna un puntatore 
            al file I/O standard; se 'type' equivale a r (read) il puntatore 
            sara' connesso allo standard output di 'cmdstring', se 'type' sara'
            w il puntatore sara' connesso allo standard input di 'cmdstring'.
RETURNS   : Un puntatore in caso di successo, NULL in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    char buf[MAX_BUF];
    FILE *fp_in, *fp_out;

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <pathname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Apertura di un file in letura */
    if ((fp_in = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Err.: %d fopen() %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Crea un pipe, definendo il programma da aprire */
    if ((fp_out = popen(PAGER, "w")) == NULL) {
        fprintf(stderr, "Err.: %d popen() %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Copia il contenuto del file passato ad argv[1] al pager */
    while (fgets(buf, MAX_BUF, fp_in) != NULL) {
        if (fputs(buf, fp_out) == EOF) {
            fprintf(stderr, "Err.: %d fputs() %s\n", errno, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    /* Verifica degli errori */
    if (ferror(fp_in)) {
        fprintf(stderr, "Err.: %d ferror() %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (pclose(fp_out) == -1) {
        fprintf(stderr, "Err.: %d pclose() %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
