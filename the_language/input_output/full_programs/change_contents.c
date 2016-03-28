#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define MAXLEN  256

typedef struct {
    uint32_t id;
    char name[MAXLEN];
    char email[MAXLEN];
} Record;

static const char *filename = "data.bin";

// Function Prototypes
Record *get_record(Record *rec);
void get_name(char *name, size_t size);
void write_record(const Record *rec, FILE *fp);
Record *read_record(Record *rec, FILE *fp);
void write_file(const char *mode);


int main(void) {
    Record myrec, newrec;
    FILE *fp;
    fp = fopen(filename, "ab+");
    get_record(&myrec);
    write_file("ab+");


    fclose(fp);
    return(EXIT_SUCCESS);
}


Record *get_record(Record *rec) {
    printf("Enter name (%d max characters): ", MAXLEN);
    get_name(rec->name, MAXLEN);

    printf("Enter mail (%d max characters): ", MAXLEN);
    get_name(rec->name, MAXLEN);

    fputs("Enter id: ", stdout);
    scanf("%u", &rec->id);

    return rec;
}

void get_name(char *name, size_t size) {
    fflush(stdout);
    fgets(name, size, stdin);
    size_t len = strlen(name);

    if (name[len-1] == '\n')
        name[len-1] = '\0';
}

void write_record(const Record *rec, FILE *fp) {
    fwrite(&rec->id, sizeof(rec->id), 1, fp);
    fwrite(rec->name, strlen(rec->name), 1, fp);
    fwrite(rec->email, strlen(rec->name), 1, fp);
}

Record *read_record(Record *rec, FILE *fp) {
    fread(&rec->id, sizeof(rec->id), 1, fp);

    fread(rec->name, strlen(rec->name), 1, fp);
    rec->name[strlen(rec->name)] = '\0';
    
    fread(rec->email, strlen(rec->name), 1, fp);
    rec->email[strlen(rec->email)] = '\0';

    return rec;
}

void write_file(const char *mode) {
    FILE *fp;
    char answer = 'y';

    if ((fp = fopen(filename, mode)) == NULL) {
        fprintf(stderr, "Err. open file, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    do {
        Record rec;
        write_record(&rec, fp);

        fputs("Another record? (y or not) : ", stdout);
        scanf("%1c", &answer);

        fflush(stdin);
    } while (tolower(answer) == 'y');

    fclose(fp);
}
