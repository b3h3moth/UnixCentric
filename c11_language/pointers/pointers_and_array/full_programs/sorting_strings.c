#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {WORD=10, SIZE=20};

void selection_sort(char (*arr)[SIZE]);

/* Lo scopo del programma e' di dichiarare ed inizializzare un array di 
stringhe, dopodiche' ordinarle. */

int main() {
    char strings[WORD][SIZE]={ 
        {"Rob Pike"},
        {"Steve Bourne"},
        {"Richard Stallman"},
        {"Theo de Raadt"},
        {"Dennis Ritchie"},
        {"Kirk Mckusick"},
        {"Brian Kernighan"}, 
        {"Ken Thopmson"},
        {"Larry Wall"},
        {"Bill Shannon"}
    };
    
    puts("Unsorted strings");
    puts("----------------");
   
    for(int i=0; i<WORD; i++)
        printf("%s\n", strings[i]);

    puts("\nSorted strings");
    puts("----------------");
   
    selection_sort(strings);
   
    for(int i=0; i<WORD; i++)
        printf("%s\n",strings[i]);

    exit(EXIT_SUCCESS);
}

void selection_sort(char (*arr)[SIZE]) {
    int n=WORD, minpos;
    char tmp[SIZE];
    
    for (int i=0; i<n-1; i++) {
        minpos = i;
        
        for (int j=i+1; j<n; j++)
            if ((strcmp(arr[j], arr[minpos])) < 0)
                minpos = j;
        
        if (minpos != i) {
            strcpy(tmp, arr[i]);
            strcpy(arr[i], arr[minpos]);
            strcpy(arr[minpos], tmp);
        }
    }
}
