#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 20

// Struttura anonima per salvataggio di dati globali, quali il nome del file
struct {
    char *filename;
    FILE *fp;
} global = { .filename = "data.bin", .fp = NULL };

struct date { 
    int day;
    int month;
    int year;
};

typedef struct date Date;

struct rec {
    Date *dt;
    char name[MAX_LEN];
    char email[MAX_LEN];
};

typedef struct rec Record;

// Function prototypes
void open_file(char *mode);

int main(void) {
    Record member;

    return(EXIT_SUCCESS);
}

static inline void close_file(void) {
    fclose(global.fp);
    global.fp = NULL;
}

void open_file(char *mode) {
    if (global.fp)
        close_file();
}
