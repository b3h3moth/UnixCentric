#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LEN 20

enum { MENU_OPTIONS=4 };

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
void delete_record(FILE *file);

int main(void) {
    FILE *fp;
    int option;
    char *faddrbook = "data.bin";

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
                add_record(fp);
                break;
            case 3:
                delete_record(fp);
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

    fputs("[1 save data] [2 add account] [3 update account] [4 delete account] "
          "[5 quit] : ",  stdout);

    scanf("%1d", &value);

    return value;
}

// Crea un file per la stampa
void save_textfile(FILE *fin) {
    FILE *fout;
    char *filename = "data.txt";

    // Informazioni di default
    DataClient client = {0, "","","",0,0};

    if ((fout = fopen(filename, "w")) == NULL) {
        fprintf(stderr, "Err. Opening file, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Salva l'offset dell'inizio del file
    rewind(fin);

    fprintf(fout, "%10s %10s %10s %10s %10s %10s\n",
            "ID", "last name", "firstname", "email", "age", "birthday");

    while (!feof(fin)) {
        fread(&client, sizeof(DataClient), 1, fin);

        if (client.id != 0) {
            fprintf(fout, "%10d %10s %10s %10s %10d %10d\n",
                    client.id, client.last_name, client.first_name,
                    client.email, client.age, client.birthday);
        }
    }

    fclose(fout);
}

// Inserisce un nuovo record
void add_record(FILE *file) {
    int account_id;
    DataClient client = {0, "","","",0,0};

    printf("New ID (1-100): ");
    scanf("%1d", &account_id);

    // Sposta il 'file position indicator' nel punto corretto del file
    fseek(file, (account_id - 1) * sizeof(DataClient), SEEK_SET);

    // Legge il record dal file
    fread(&client, sizeof(DataClient), 1, file);

    if (client.id != 0)
        printf("Record #%d already contains info\n", client.id);
    else {
        printf("enter \'last name\', \'first name\', \'email\', "   \
               "\'age\',\'birthday\'\n: ");
        scanf("%s%s%s%d%d", client.last_name, client.first_name,    \
                client.email, &client.age, &client.birthday);

        client.id = account_id;
        
        // Sposta il 'file position indicator' nel punto corretto del file
        fseek(file, (client.id - 1) * sizeof(DataClient), SEEK_SET);

        // salva il record nel file
        fwrite(&client, sizeof(DataClient), 1, file);
    }
}

// Rimuove un record
void delete_record(FILE *file) {
    int account_id;
    DataClient client = {0, "","","",0,0};

    // Record da rimuovere
    printf("New ID (1-100): ");
    scanf("%1d", &account_id);

    // Sposta il 'file position indicator' nel punto corretto del file
    fseek(file, (account_id - 1) * sizeof(DataClient), SEEK_SET);

    // Legge il record dal file
    fread(&client, sizeof(DataClient), 1, file);

    if (client.id == 0)
        printf("Record #%d doesn't exist\n", client.id);
    else {
        // Sposta il 'file position indicator' nel punto corretto del file
        fseek(file, (account_id - 1) * sizeof(DataClient), SEEK_SET);

        // sovrascrive il record con uno vuoto
        fwrite(&client, sizeof(DataClient), 1, file);
    }
}
