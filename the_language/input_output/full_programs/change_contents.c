#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

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

int main(void) {
    Record myrec;
    FILE *fp;
    fp = fopen(filename, "ab+");
    get_record(&myrec);
    write_record(&myrec, fp);

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
