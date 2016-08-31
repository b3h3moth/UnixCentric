#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 72

/* Lo scopo del programma e' di simulare mediante fgetpos() e fsetpos() il
concetto di SEEK_SET e SEEK_END associato a fseek(). */

int main(int argc, char *argv[]) {
    FILE *fp;
    fpos_t pos_beg, pos_end;
    size_t data_len;
    char buf[MAX_BUF];
    int rc, ch;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Err. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
   
    // Imposta pos_beg all'inizio del file, ovvero SEE_SET
    rc = fgetpos(fp, &pos_beg);
    if (rc != 0) {
        fprintf(stderr, "Err. fgetpos() at the beginning, %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Si fa andare avanti lo stream finche' giunge alla fine del file
    do {
        ch = fgetc(fp);
    } while (ch != EOF);
    
    if (feof(fp)) {
        /* Imposta pos_end alla fine del file, dopo l'ultimo byte, ovvero come
        se fosse SEEK_END */
        rc = fgetpos(fp, &pos_end);
        
        if (rc != 0) {
            fprintf(stderr, "Err. fgetpos() at the end, %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    /* Il 'file position indicator' ora punta alla fine dello stream, per cui
    se si volessero stampare sullo standard output i primi MAX_BUF caratteri
    dello stream, si dovrebbe sportarlo all'inizio del file */
    rc = fsetpos(fp, &pos_beg);
    if (rc != 0) {
        fprintf(stderr, "Err. fsetpos() back to beginning%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    data_len = fread(buf, sizeof(char), MAX_BUF, fp);
    buf[MAX_BUF-1] = '\0';

    fclose(fp);

    printf("Read from \'%s\', first \'%d\' characters:\n", argv[1], data_len);
    printf("%s\n", buf);
    printf("BEG: %ld\nEND: %ld\n", pos_beg.__pos, pos_end.__pos);

    return(EXIT_SUCCESS);
}
