#include <stdio.h>
#include <stdlib.h>
//#include "readline.h"

#define MAX_LEN 25
#define MAX_HW 100  // Compomenti Hardware

struct hw {
    int number;
    char name[MAX_LEN+1];
    int on_hand;
}; 

typedef struct hw Hardware; 

Hardware inventory[MAX_HW];

// Il numero dei componenti hardware memorizzati
int num_hw_components = 0;

int insert(void);
void update(void);
void search(void);
void print(void);
int find_component(int num);

int main(void) {
    char code;

    for (;;) {
        printf("[i]nsert [u]pdate [s]earch] [p]rint [q]uit: ");
        scanf("%c", &code);

        /* Salta a fine riga, consentendo una interazione col menu'
        pulita e ben formattata */
        while (fgetc(stdin) != '\n')
            ;

        switch (code) {
            case 'i': insert(); break;
            case 'u': update(); break;
            case 's': search(); break;
            case 'p': print(); break;
            case 'q': return(EXIT_SUCCESS);
        }
    }

    return(EXIT_SUCCESS);
}

int insert(void) {
    fputs("insert\n", stdout);
}
void update(void) {
    fputs("update\n", stdout);
}
void search(void) {
    fputs("search\n", stdout);
}
void print(void) {
    fputs("print\n", stdout);
}

/* Cerca un articolo nel vettore inventory, restituisce l'indice del vettore
qualora la ricerca fosse positiva, EXIT_FAILURE altrimenti */
int find_component(int num) {
    for (int i=0; i<num_hw_components; i++)
        if (inventory[i].number == num)
            return i;

    return(EXIT_FAILURE);
}
