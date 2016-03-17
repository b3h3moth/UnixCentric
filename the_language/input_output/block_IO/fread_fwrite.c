#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void) {
    FILE *fp;
    int val = 255, valb;
    int vec[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    int vec_size = sizeof(vec) / sizeof(vec[0]);
    int vecb[vec_size];
    fpos_t pos_one, pos_two;


    if ((fp = fopen("data.bin", "wb+")) == NULL) {
        fprintf(stderr, "Err. open stream with fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Scrive l'intero di quattro byte 'val' nello stream 'fp'
    fwrite(&val, sizeof(int), 1, fp);
    // Salva l'offset
    fgetpos(fp, &pos_one);

    /* Sposta il file pointer all'inizio del file per consentire alla funzione
    fread() di poter leggere i dati */
    fseek(fp, 0, SEEK_SET);

    // Legge un intero da dallo stream 'fp' salvandolo in valb
    fread(&valb, sizeof(int), 1, fp);
    printf("val backup is: %d\n", valb);

    // Scrive un vettore di 'vec_size' elementi nello stream 'fp'
    if (fwrite(&vec, vec_size, 12, fp) != vec_size) {
        fprintf(stderr, "Err. writing vector to stream with fwrite()n");
        exit(EXIT_FAILURE);
    }
   
    // Riprende l'offset salvato subito dopo la scrittura dell'intero 'val'
    fsetpos(fp, &pos_one);
    fread(&vecb, sizeof(int), vec_size, fp);

    fputs("valb vector backup is: ", stdout);
    for (int i=0; i<vec_size; i++)
        printf("%d, ", vecb[i]);

    fclose(fp);
    return(EXIT_SUCCESS);
}
