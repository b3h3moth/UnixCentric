#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

enum {CH_MAX=6, TIME_LEN=17, TEXT_LEN=150} info_note;

struct note {
    uint32_t id;
    char date_time[TIME_LEN];
    char text[TEXT_LEN];
};

typedef struct note Note;

// Function prototypes
void init_note(char *filename);
void add_note(FILE *file, Note *note);
void read_note(FILE *file, Note *note);
void usage(char *filename);

/* Lo scopo del programma e' di mantenere un database testuale con note di una
grandezza massima di TEXT_LEN. Ciascuna nota sara' corredata della data.
Le opzioni sono -r o read per leggere le note e -a o add per scriverle. */

int main(int argc, char *argv[]) {
    FILE *fp;
    //struct stat f_stat;
    Note *mynote = malloc(sizeof(Note));
    char *filename = "data.bin";

    if ((argc != 2)) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    //if(stat(filename, &f_stat) != 0)
    //    init_note(filename);

    if ((fp = fopen(filename, "ab+")) == NULL) {
        fprintf(stderr, "Err. writing note: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if ((strcmp(argv[1], "add") == 0) || (strcmp(argv[1], "-a") == 0))
        add_note(fp, mynote);
    else if ((strcmp(argv[1], "read") == 0) || (strcmp(argv[1], "-r") == 0))
        read_note(fp, mynote);
    else if ((strcmp(argv[1], "init") == 0) || (strcmp(argv[1], "-i") == 0))
        init_note(filename);
    else
        usage(argv[0]);

    fclose(fp);
    free(mynote);
    return(EXIT_SUCCESS);
}

// Inizializza il database delle note, utile anche se si volesse azzererarlo
void init_note(char *filename) {
    FILE *fp;

    if ((fp = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "Err. creating DB notes; %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fclose(fp);
}

// Ogni nota ha un proprio id 
static int set_id(FILE *file, Note* note) {
    size_t nrec = 1;

    fseek(file, 0, SEEK_SET);
    
    while (fread(note, sizeof(Note), 1, file) != 0) {
        nrec++;
        if (feof(file))
            puts("End of file was reached.\n");
        if (ferror(file)) {
            puts("An error when reading file occurred.\n");
            exit(EXIT_FAILURE);
        }
    }

    return nrec;
}

// Aggiunge una nota
void add_note(FILE *file, Note *note) {
    time_t cur = time(NULL);
    char *fmt = "%Y-%m-%d %H:%M";

    note->id = set_id(file, note);

    if (strftime(note->date_time, TIME_LEN, fmt, localtime(&cur)) == 0 ) {
        fprintf(stderr, "Err. getting note, fgets(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Note: ");
    
    /* Azzera tutti i campi del testo, in modo tale che la nota sara' inserita
    per la sola lunghezza e non ci saranno intralci da buffer precedenti; 
    e' stato considerato anche fflush(stdout), ma non ha prodotto risultati
    significativi */
    memset(note->text, '\0', TEXT_LEN);

    if (fgets(note->text, TEXT_LEN, stdin) == NULL) {
        fprintf(stderr, "Err. getting note, fgets(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (strlen(note->text) < CH_MAX) {
        fprintf(stderr, "Warning: A note less than \'%d\' is not accepted.\n",
                CH_MAX-1);
        exit(EXIT_FAILURE);
    }

    fwrite(note, sizeof(Note), 1, file);
}

// Legge tutte le note
void read_note(FILE *file, Note *note) {
    fseek(file, 0, SEEK_SET);

    while (fread(note, sizeof(Note), 1, file) != 0) {
        if (ferror(file)) {
            fprintf(stderr, "Error when reading file, %s", strerror(errno));
            exit(EXIT_FAILURE);
        }
        printf("%s %s", note->date_time, note->text);
    }
}

void usage(char *filename) {
    fprintf(stderr, "Usage: %s [-a, add] [-r read]\n", filename);
}
