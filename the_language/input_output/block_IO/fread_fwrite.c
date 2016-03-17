#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void) {
    int val = 255;
    int vec[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
    int valb;

    FILE *fp;

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

    fclose(fp);
    return(EXIT_SUCCESS);
}
