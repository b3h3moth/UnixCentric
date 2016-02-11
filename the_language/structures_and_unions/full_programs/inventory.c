#include <stdio.h>
#include <stdlib.h>
//#include "readline.h"

#define MAX_LEN 25
#define MAX_COMPONENTS 100  // Componenti Hardware

struct hw {
    int number;
    char name[MAX_LEN+1];
    int on_hand;
}; 

typedef struct hw Hardware; 

Hardware inventory[MAX_COMPONENTS];

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
        scanf(" %c", &code);

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
            default: printf("Legal codes are [i] [u] [s] [p] [q]\n");
        }
    }

    return(EXIT_SUCCESS);
}

/* Inserisce un componente nel database; nel caso fosse gia' presente nel db 
opppure il db stesso fosse pieno restituisce un messaggio di errore */
int insert(void) {
    int component_num;

    if (num_hw_components == MAX_COMPONENTS) {
        printf("DB is full\n");
        return;
    }

    printf("Enter component number: ");
    scanf("%d", &component_num);

    // Verifica se un componente gia' esiste
    if (find_component(component_num) >= 0) {
        printf("Component already exists.\n");
        return;
    }
    inventory[component_num].number = component_num;

    printf("Enter component name: ");
    //read_line(inventory[component_num].name, MAX_LEN);

    printf("Enter quantity: ");
    scanf("%d", &inventory[component_num].on_hand);

    component_num++;
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

    return (-1);
}
