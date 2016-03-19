#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct data {
    int id;
    char name[20];
    char email[30];
};

/* Lo scopo del programma a' di scrivere diverse strutture su un file binario,
dopodiche' leggere i dati dal file e stamparli sullo stdout */

int main(void) {
    FILE *fp;
    struct data mydata, *mydata4;
    struct data mydata1 = {1, "Rob Pike", "rob@pike.org"};
    struct data mydata2 = {2, "Richard Stallman", "richard@stallman.org"};
    struct data mydata3 = {3, "Larry Wall", "larry@wall.org"};
    
    if ((fp = fopen("data.bin", "wb+")) == NULL) {
        fprintf(stderr, "Err. opening file, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fwrite(&mydata1, sizeof(struct data), 1, fp);
    fwrite(&mydata2, sizeof(struct data), 1, fp);
    fwrite(&mydata3, sizeof(struct data), 1, fp);

    /* Poiche' 'mydata4' e' un puntatore a una 'struct data', prima di poter
    inizializzarla con i dati ricevuti dal file, si deve allocare la memoria */
    mydata4 = malloc(sizeof(struct data));

    // Si riempie la struttura
    mydata4->id = 4;
    strcpy(mydata4->name, "Ken Thopmson");
    strcpy(mydata4->email, "ken@thopmson.org");

    /* Si scrive sul file, avendo l'accortezza di non utilizzare l'operatore
    'address of (&)' poiche' si sta lavorando con puntatori */
    fwrite(mydata4, sizeof(struct data), 1, fp);

    /* Per leggere e' necessario posizionare il 'file position indicator' 
    all'inizio del file */
    fseek(fp, 0, SEEK_SET);

    // Lettura di tutto cio' che e' stato scritto nel file
    while (fread(&mydata, sizeof(struct data), 1, fp))
        printf("%d %s %s\n", mydata.id, mydata.name, mydata.email);

    fclose(fp);
    return(EXIT_SUCCESS);
}
