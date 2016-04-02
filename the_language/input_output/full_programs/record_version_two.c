#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define MAXLEN  256

typedef struct {
    char name[MAXLEN];
    int id;
} Record;

static const char *filename = "data.bin";

// Function Prototypes
Record *get_person(Record *rec);
void get_name(char *name, size_t size);
void write_record(const Record *rec, FILE *fp);
Record *read_record(Record *rec, FILE *fp);
void write_file(const char *mode);
void list_file(void);


int main(void) {
    char answer = 'q';

    while (1) {
        fputs("(l) list file contents\n"
              "(c) create new file\n"
              "(a) add new record/s\n"
              "(q) quit\n", stdout);
        scanf("%1c", &answer);

        switch(tolower(answer)) {
            case 'l': 
                list_file();
                break;
            case 'c':
                write_file("wb+");
                fputs("\nCreate file: done.\n", stdout);
                break;
            case 'a':
                write_file("ab+");
                fputs("\nAppend to file: done.\n", stdout);
            case 'q':
                fputs("Quit: done.\n", stdout);
                exit(EXIT_SUCCESS);
            default:
                fputs("\nInvalid argument.\n", stdout);
                break;
        }
    }

    // Testing 

    return(EXIT_SUCCESS);
}


Record *get_person(Record *rec) {
    printf("Enter name (%d max characters): ", MAXLEN);
    get_name(rec->name, MAXLEN);

    fputs("Enter id: ", stdin);
    scanf(" %d", &rec->id);

    return rec;
}

void get_name(char *name, size_t size) {
    fflush(stdin);

    fgets(name, size, stdin);
    size_t len = strlen(name);

    if (name[len-1] == '\n')
        name[len-1] = '\0';
}

/* Scrive la lunghezza della stringa - membro name - seguita dalla stringa
stessa e dall'id. Cio' consente in fase di lettura di leggere anche la
lunghezza della stringa e quindi regolarsi di conseguenza */
void write_record(const Record *rec, FILE *fp) {
    size_t len = strlen(rec->name);

    fwrite(&len, sizeof(len), 1, fp);
    fwrite(rec->name, sizeof(char), len, fp);
    fwrite(&rec->id, sizeof(rec->id), 1, fp);
}

// Legge il record dal file e lo salva nella struttura apposita
Record *read_record(Record *rec, FILE *fp) {
    size_t len = 0;

    // Legge la lunghezza della stringa
    fread(&len, sizeof(len), 1, fp);
    if (feof(fp))
        return NULL;

    fread(rec->name, sizeof(char), len, fp);
    rec->name[len] = '\0';
    
    fread(&rec->id, sizeof(rec->id), 1, fp);

    return rec;
}

// Scrive un numero arbitrario di record all'interno del file
void write_file(const char *mode) {
    FILE *fp;
    char answer = 'y';

    if ((fp = fopen(filename, mode)) == NULL) {
        fprintf(stderr, "Err. open file, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    do {
        Record rec;
        write_record( get_person(&rec), fp);

        fputs("Another record? (y or not) : ", stdout);
        scanf("%1c", &answer);
        fflush(stdin);
    } while (tolower(answer) == 'y');

    fclose(fp);
}

void list_file(void) {
    Record rec;
    FILE *fp;

    if ((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Err. open file, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (read_record(&rec, fp))
        printf("%s %d", rec.name, rec.id);

    fputs(" ", stdout);
    fclose(fp);
}
