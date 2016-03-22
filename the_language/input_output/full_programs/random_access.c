#include <stdio.h>
#include <stdlib.h>

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

struc
int main(void) {
    return(EXIT_SUCCESS);
}
