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
    struct data mydata1 = {1, "luca suriano", "luka@autistici.org"};
    struct data mydata2 = {2, "richard stallman", "rms@stallman.org"};
    struct data mydata3 = {3, "Larry Wall", "larry@perl.org"};
    struct data mydata;
    
    if ((fp = fopen("data.bin", "wb+")) == NULL) {
        fprintf(stderr, "Err. opening file, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fwrite(&mydata1, sizeof(struct data), 1, fp);
    fwrite(&mydata2, sizeof(struct data), 1, fp);
    fwrite(&mydata3, sizeof(struct data), 1, fp);

    fseek(fp, 0, SEEK_SET);

    while (fread(&mydata, sizeof(struct data), 1, fp))
        printf("%d %s %s\n", mydata.id, mydata.name, mydata.email);

    fclose(fp);
    return(EXIT_SUCCESS);
}
