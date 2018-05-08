#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char NONWORD[] = "\n";

enum { 
    // Numero parole per il prefisso
    NPREF = 2,
    // Dimensione dell'array della hashtable degli stati
    NHASH = 4093,
    // Numero massimo di parole generate
    MAXGEN = 10000,
    
    MULTIPLIER = 31
};

typedef struct State State;
typedef struct Suffix Suffix;

/* Lista dei prefissi + suffissi */
struct State {
    char *pref[NPREF];  /* Parole di prefisso */
    Suffix *suf;        /* lista di suffissi */
    State *next;        /* prossimo elemento della hashtable */
};

/* Lista suffissi */
struct Suffix {
    char *word;         /* Suffisso */
    Suffix *next;       /* prossimo elemento nella lista dei suffissi */
};

/* Tabella hash degli stati */
State *statetab[NHASH];

// Prototipi
unsigned int hash(char *s[NPREF]);
State *lookup(char *prefix[NPREF], int create);
void build(char *prefix[NPREF], FILE *f);
void add(char *prefix[NPREF], char *suffix);
void addsuffix(State *sp, char *suffix);
void generate(int nwords);

/* Generazione di testo casuale della catena di markov */
int main(void) {
    int i, nwords = MAXGEN;
    char *prefix[NPREF];

    for (i=0; i<NPREF; i++)
        prefix[i] = NONWORD;
    build(prefix, stdin);
    add(prefix, NONWORD);
    generate(nwords);

    return(EXIT_SUCCESS);
}

/* Calcola il valore hash per un array di NPREF stringhe; hashing */
unsigned int hash(char *s[NPREF]) {
    unsigned int h = 0;
    unsigned char *p;
    int i;

    for (i=0; i<NPREF; i++)
        for (p = (unsigned char *) s[i]; *p != '\0'; p++)
            h = MULTIPLIER * h + *p;

    return h % NHASH;
}

/* Ricerca il prefisso e lo crea se richiesto */
State *lookup(char *prefix[NPREF], int create) {
    int i, h;
    State *sp;

    h = hash(prefix);

    for (sp = statetab[h]; sp != NULL; sp = sp->next) {
        for (i=0; i<NPREF; i++)
            if (strcmp(prefix[i], sp->pref[i]) != 0)
                break;
        if (i == NPREF) /* trovato */
            return sp;
    }

    if (create) {
        sp = (State *) malloc(sizeof(State));
        for (i=0; i<NPREF; i++)
            sp->pref[i] = prefix[i];
        sp->suf = NULL;
        sp->next = statetab[h];
        statetab[h] = sp;
    }

    return sp;
}

// Legge l'input e costruisce la tabella dei prefissi
void build(char *prefix[NPREF], FILE *f) {
    char buf[100];
    char fmt[10];

    // Crea una stringa
    sprintf(fmt, "%%%ds", sizeof(buf)-1);

    while(fscanf(f, fmt, buf) != EOF)
        add(prefix, (char *)strdup(buf));
}

// Aggiunge una parola alla lista dei suffissi, aggiorna anche prefix
void add(char *prefix[NPREF], char *suffix) {
    State *sp;

    sp = lookup(prefix, 1); // Nel caso non fosse trovato lo creerebbe

    addsuffix(sp, suffix);

    // Spostamento delle parole di prefix
    memmove(prefix, prefix+1, (NPREF-1)*sizeof(prefix[0]));
    prefix[NPREF-1] = suffix;
}

// Aggiunta di una parola a una lista di suffissi
void addsuffix(State *sp, char *suffix) {
    Suffix *suf;

    suf = (Suffix *) malloc(sizeof(Suffix));
    suf->word = suffix;
    suf->next = sp->suf;
    sp->suf = suf;
}

// Produce l'output, una parola per linea
void generate(int nwords) {
    State *sp;
    Suffix *suf;
    char *prefix[NPREF], *w;
    int i, nmatch;

    for (i=0; i<NPREF; i++)
        prefix[i] = NONWORD;

    for (i=0; i<nwords; i++) {
        sp = lookup(prefix, 0);
        nmatch = 0;

        for (suf = sp->suf; suf != NULL; suf = suf->next)
            if (rand() % ++nmatch == 0)
                w = suf->word;

        if (strcmp(w, NONWORD) == 0)
            break;

        printf("%s\n", w);
        memmove(prefix, prefix+1, (NPREF-1)*sizeof(prefix[0]));
        prefix[NPREF-1] = w;
    }
}
