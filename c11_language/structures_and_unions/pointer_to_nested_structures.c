#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME	10
#define MAX_STR		20

struct name {
   char first[MAX_NAME];
   char last[MAX_NAME];
};

struct rec {
   char title[MAX_STR];
   struct name author;
   unsigned int year;
};

/* Si dichiara un puntatore al tipo di dato struct 'rec' */
typedef struct rec *Record;

int main(int argc, char *argv[]) {
    Record test;

    /* Allocazione della memoria per il tipo di dato Record, ovvero un
    puntatore alla struttura 'rec' */
    test = malloc(sizeof(Record));

    test->year = 1970;
    strcpy(test->title, "Il cacciatore");
    strncpy(test->author.first, "Michael", 7);
    strncpy(test->author.last, "Cimino", 6);
    
    printf("%i\n", test->year);
    printf("%s\n", test->title);
    printf("%s\n", test->author.first);
    printf("%s\n", test->author.last);

   return(EXIT_SUCCESS);
}

