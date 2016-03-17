#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LEN 20

struct data {
    int id;
    char nickname[MAX_LEN];
    char email[MAX_LEN];
};

typedef struct data Record;

int main(void) {
    FILE *fp;
    int val = 255, valb;
    int vec[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    int vec_size = sizeof(vec) / sizeof(vec[0]);
    int vecb[vec_size];
    fpos_t pos_one, pos_two;
    Record mydata = {1, "b3h3m0th", "b3h3m0th@email.org"};


    if ((fp = fopen("data.bin", "wb+")) == NULL) {
        fprintf(stderr, "Err. open stream with fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Scrive l'intero di quattro byte 'val' nello stream 'fp'
    fwrite(&val, sizeof(int), 1, fp);

    // Salva l'offset subito dopo la scrittura dell'intero
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
   
    // Riprende il primo offset
    fsetpos(fp, &pos_one);

    // Inizializza il vettore 'vecb' con i dati letti dallo stream 'fp
    fread(&vecb, sizeof(int), vec_size, fp);

    fputs("valb vector backup is: ", stdout);
    for (int i=0; i<vec_size; i++)
        printf("%d, ", vecb[i]);

    // Scrive la struttura 'mydata' nello stream fp
    fwrite(&mydata, sizeof(Record), 1, fp);

    fclose(fp);
    return(EXIT_SUCCESS);
}
