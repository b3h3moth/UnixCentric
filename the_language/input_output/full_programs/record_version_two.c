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
            case 'q': case 'Q':
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
    size_t len_name = strlen(rec->name);
    size_t len_email = strlen(rec->email);

    fwrite(&len_name, sizeof(len_name), 1, fp);
    fwrite(rec->name, sizeof(char), len_name, fp);

    fwrite(&len_email, sizeof(len_email), 1, fp);
    fwrite(rec->email, sizeof(char), len_email, fp);

    fwrite(&rec->id, sizeof(rec->id), 1, fp);
}

Record *read_record(Record *rec, FILE *fp) {
    size_t len_name = 0;
    size_t len_email = 0;

    fread(&len_name, sizeof(len_name), 1, fp);
    fread(rec->name, sizeof(char), len_name, fp);
    rec->name[len_name] = '\0';
    
    fread(&len_email, sizeof(len_email), 1, fp);
    fread(rec->email, sizeof(char), 1, fp);
    rec->email[len_email] = '\0';

    fread(&rec->id, sizeof(rec->id), 1, fp);

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

void list_file(void) {
    Record rec;
    FILE *fp;


    if ((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Err. open file, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (read_record(&rec, fp))
        printf("%s %s %d", rec.name, rec.email, rec.id);

    fputs(" ", stdout);
    fclose(fp);
}
