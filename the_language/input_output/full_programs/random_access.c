#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 20

// Struttura anonima per salvataggio di dati globali, quali il nome del file
struct {
    char *filename;
    FILE *fp;
} global = { .filename = "data.bin", .fp = NULL };

typedef struct date {
    int day;
    int month;
    int year;
} Date;

struct data {
    Date *dt;
    char name[MAX_LEN];
    char email[MAX_LEN];
};

typedef struct data Record;

// Function prototypes
void open_file(char *mode);
void get_name(char *name, size_t size);
bool get_record(Record *rec);

int main(void) {
    Record member;

    while (get_record(&member)) {
        fwrite(&member, sizeof(Record), 1, global.fp);
    }

    return(EXIT_SUCCESS);
}

inline void close_file(void) {
    fclose(global.fp);
    global.fp = NULL;
}

void open_file(char *mode) {
    if (global.fp)
        close_file();
}

void get_name(char *name, size_t size) {
    fgets(name, size, stdin);
    
    if (name[strlen(name)-1] == '\n')
        name[strlen(name)-1] = '\0';
}

bool get_record(Record *rec) {
    puts("Name: ");
    get_name(rec->name, sizeof(rec->name));
    return true;
}
