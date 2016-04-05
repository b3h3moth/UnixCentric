#include <stdio.h>
#include <stdlib.h>

#define MAXLEN  256

int find_str(FILE *fp, const char *str);

/* Lo scopo del programma e' di cercare, mediante la funzione find_str(), 
tutte le linee del file, e stamparle sullo stdout, in cui ci dovesse essere una
corrispondenza con la stringa fornita alla funzione stessa */

int main(void) {
    return(EXIT_SUCCESS);
}

int find_str(FILE *fp, const char *str) {

