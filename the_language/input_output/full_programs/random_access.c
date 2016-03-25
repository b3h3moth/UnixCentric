#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LEN 30

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
    Date dt;
    char name[MAX_LEN];
    char email[MAX_LEN];
};

typedef struct data Record;

// Function prototypes
void open_file(char *mode);
void get_name(char *name, size_t size);
void get_record(Record *rec);
void print_record(void);
void find_record(char *str);

static inline void close_file(void) {
    fclose(global.fp);
    global.fp = NULL;
}

int main(void) {
    Record member;
    open_file("ab");
    get_record(&member);
    fwrite(&member, sizeof(Record), 1, global.fp);
    close_file();

    print_record();

    find_record("luca");

    return(EXIT_SUCCESS);
}


void open_file(char *mode) {
    if (global.fp)
        close_file();

    if ((global.fp = fopen(global.filename, mode)) == NULL) {
        fprintf(stderr, "Err. opening file, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

}

void get_name(char *name, size_t size) {
    fflush(stdout);
    fgets(name, size, stdin);
    size_t len = strlen(name);
    
    if (name[len-1] == '\n')
        name[len-1] = '\0';
}

void get_record(Record *rec) {
    fputs("give Name: ", stdout);
    get_name(rec->name, sizeof(rec->name));

    fputs("give E-Mail: ", stdout);
    get_name(rec->email, sizeof(rec->email));

    fputs("give Birthday (dd/mm/dddd): ", stdout);
    scanf("%d %d %d", &rec->dt.day, &rec->dt.month, &rec->dt.year);
}

void print_record(void) {
    Record rec;
    open_file("rb");

    while (fread(&rec, sizeof(Record), 1, global.fp) != 0)
        printf("%s %s %d/%d/%d\n", rec.name, rec.email, rec.dt.day, \
                rec.dt.month, rec.dt.year);

    close_file();
}

void find_record(char *str) {
    Record temp;
    int found = 0;
    open_file("rb");

    fseek(global.fp, 0L, SEEK_SET);    // Equivalente a rewind(global.fp)

    while (fread(&temp, sizeof(Record), 1, global.fp) != 0) {
        if (strstr(temp.name, str)) {
            printf("Found, e-mail is: %s", temp.email);
            found++;
        }
    }

    close_file();
}
