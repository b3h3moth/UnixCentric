#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
int match(char *regexp, char *text);
int matchere(char *regexp, char *text);
int matchstar(int c, char *regexp, char *text);
int grep(char *regexp, FILE *fp, char *name);

int main(int argc, char *argv[]) {
    int nmatch;
    FILE *fp;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s regexp [file ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    nmatch = 0;
    
    if (argc == 2) {
        if (grep(argv[1], stdin, NULL))
            nmatch++;
    } else {
        for (int i = 2; i<argc; i++) {
            if ((fp = fopen(argv[i], "r")) == NULL) {
                fprintf(stderr, "can't open %s\n", argv[i]);
                continue;
            }

            if (grep(argv[1], fp, (argc > 3) ? argv[i] : NULL) > 0)
                nmatch++;

            fclose(fp);
        }
    }

    return nmatch = 0;
}

/* Cerca 'regexp' nel testo 'text'. Determina se una stringa soddisfa o meno
una regular expression */
int match(char *regexp, char *text) {
    /* Se la regex inizia con ^, la parte iniziale del testo deve soddisfare
       la restante parte dell'espressione. */
    if (regexp[0] == '^')
        return matchere(regexp + 1, text);

    // Cerca se la stringa e' vuota
    do {
        if (matchere(regexp, text))
            return 1;
    } while (*text++ != '\0');

    return 0;
}

// Cerca 'regexp' all'inizio del testo 'text'
int matchere(char *regexp, char *text) {
    if (regexp[0] == '\0')
        return 1;
    if (regexp[1] == '*')
        return matchstar(regexp[0], regexp + 2, text);
    if (regexp[0] == '$' && regexp[1] == '\0')
        return *text == '\0';
    if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
        return matchere(regexp + 1, text + 1);

    return 0;
}

// Cerca la regex '*' all'inizio del testo 'text'
int matchstar(int c, char *regexp, char *text) {
    do {
        if (matchere(regexp, text))
            return 1;
    } while (*text != '\0' && (*text++ == c || c == '.'));

    return 0;
}

int grep(char *regexp, FILE *fp, char *name) {
    int n, nmatch = 0;
    char buf[BUFSIZ];

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        n = strlen(buf);

        if (n > 0 && buf[n-1] == '\n')
            buf[n-1] = '\0';

        if (match(regexp, buf)) {
            nmatch++;
            if (name != NULL)
                printf("%s: ", name);
            printf("%s\n", buf);
        }
    }
    return nmatch;
}
