#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void) {
    FILE *fp;
    int val = 255;
    int vec[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    int valb;
    int vec_size = sizeof(vec) / sizeof(vec[0]);


    if ((fp = fopen("data.bin", "ab+")) == NULL) {
        fprintf(stderr, "Err. open stream with fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Scrive l'intero di quattro byte 'val' nello stream 'fp'
    fwrite(&val, sizeof(int), 1, fp);

    /* Sposta il file pointer all'inizio del file per consetire alla funzione
    fread() di poter leggere i dati */
    fseek(fp, 0, SEEK_SET);

    // Legge un intero da dallo stream 'fp' salvandolo in valb
    fread(&valb, sizeof(int), 1, fp);
    printf("val backup is: %d\n", valb);

    // Scrive un vettore di 'vec_size' elementi nello stream 'fp'
    fwrite(&vec, sizeof(vec)/sizeof(vec[0]), 1, fp);

    fclose(fp);
    return(EXIT_SUCCESS);
}
