#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LEN 20

enum { MENU_OPTIONS=5 };

struct client_data {
    int id;
    char last_name[MAX_LEN];
    char first_name[MAX_LEN];
    char email[MAX_LEN];
    int age;
    int birthday;
};

typedef struct client_data DataClient;

// Prototipi
int set_option(void);
void save_textfile(FILE *file);
void add_record(FILE *file);

int main(void) {
    FILE *fp;
    int option;
    char *faddrbook = "addressbook.bin";

    if ((fp = fopen(faddrbook, "ab+")) == NULL) {
        fprintf(stderr, "Err. opening file. fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ( (option = set_option()) != MENU_OPTIONS) {
        switch (option) {
            case 1:
                save_textfile(fp);
                break;
            case 2:
                puts("2");
                break;
            case 3:
                puts("3");
                break;
            case 4:
                puts("4");
                break;
            default:
                fputs("Unknow option\n", stdout);
                break;
        }
    }

    fclose(fp);
    return(EXIT_SUCCESS);
}

// Il menu' a scelta delle opzioni
int set_option(void) {
    int value;

    fputs("[1] save data for printing\n"
          "[2] add a new account\n"
          "[3] update a new account\n"
          "[4] delete an account\n"
          "[5] quit\n : ",  stdout);

    scanf("%1d", &value);

    return value;
}

// Crea un file per la stampa
void save_textfile(FILE *fin) {
    FILE *fout;
    char *filename = "account.txt";
    fpos_t fpos_beginning;

    // Informazioni di default
    DataClient client = {0, "","","",0,0};

    if ((fout = fopen(filename, "w")) == NULL) {
        fprintf(stderr, "Err. Opening file, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Salva l'offset dell'inizio del file
    rewind(fin);

    fprintf(fout, "%10s %10s %10s %10s %10s %10s\n",
            "id", "last name", "firstname", "email", "age", "birthday");

    while (!feof(fin)) {
        fread(&client, sizeof(DataClient), 1, fin);
    }

    fclose(fout);
}

// Inserisce un nuovo record
void add_record(FILE *file) {
