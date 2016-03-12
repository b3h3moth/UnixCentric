#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LEN  25

/* Lo scopo del programma e' di inizializzare un array di MAX_LEN elementi 
con un numero casuale (1 < N < 1000), dopodiche' scrivere l'intero array in un
file binario mediante la funzione fwrite(). Infine leggere i dati scritti
copiando ciascun valore in una copia dell'array di partenza.*/

int main(void) {
    FILE *fout, *fin;
    char *binfile = "data.bin";
    int data[MAX_LEN], datacopy[MAX_LEN], n;

    fout = fopen(binfile, "wb");

    if (fout == NULL) {
        perror("fopen()");
        exit(EXIT_FAILURE);
    }

    for (int i=0; i<MAX_LEN; i++)
        *(data + i) = rand() % 1000;

    n = fwrite(data, sizeof(data[0]), sizeof(data)/sizeof(data[0]), fout);
    fclose(fout);

    printf("Written \'%d\' elements and \'%d\' byte to file: \'%s\'\n", \
            n, n * sizeof(int), binfile);

    // Lettura dal file binario appena creato 'binfile'
    fin = fopen(binfile, "r");

    if (fout == NULL) {
        perror("fopen()");
        exit(EXIT_FAILURE);
    }

    n = fread(datacopy, sizeof(int), MAX_LEN, fin);
    for(int i=0; i<n; i++)
        printf("data[%d] = %d\n", i, datacopy[i]);

    fclose(fin);

    return(EXIT_SUCCESS);
}
