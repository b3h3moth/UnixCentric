#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define MAX_LEN 25
#define MAX_COMPONENTS 100  // Componenti Hardware

struct hw {
    int number;
    char name[MAX_LEN+1];
    int on_hand;
}; 

typedef struct hw Hardware; 

Hardware dbcomponent[MAX_COMPONENTS];

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
            default: printf("\nLegal codes are [i] [u] [s] [p] [q]\n");
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
        return(1);
    }

    printf("Enter component number: ");
    scanf("%d", &component_num);

    // Verifica se un componente gia' esiste
    if (find_component(component_num) >= 0) {
        printf("Component already exists.\n");
        return(1);
    }
    dbcomponent[num_hw_components].number = component_num;

    printf("Enter component name: ");
    read_line(dbcomponent[num_hw_components].name, MAX_LEN);

    printf("Enter quantity: ");
    scanf("%d", &dbcomponent[num_hw_components].on_hand);

    return num_hw_components++;
}

/* Verifica il numero di componente, se non esiste stampa un messaggio di 
errore, in caso contrario modifica la quantita' disponibile */
void update(void) {
    int i, num, change;

    printf("Enter component number: ");
    scanf("%d", &num);

    i = find_component(num);

    if (i >= 0) {
        printf("Enter quantity to change: ");
        scanf("%d", &change);
        dbcomponent[i].on_hand += change;
    } else 
        printf("Component not found.\n");
}

// Cerca un componente nel db
void search(void) {
    int i, num;

    printf("Enter component number: ");
    scanf("%d", &num);

    i = find_component(num);

    if (i >= 0) {
        printf("  Component name: %s\n", dbcomponent[i].name);
        printf("Quantity on hand: %d\n", dbcomponent[i].on_hand);
    } else
        printf("Component not found.\n");
}

// Stampa la lista dei componenti hardware
void print(void) {
    if (num_hw_components <= 0) {
        printf("List of hardware components is empty.\n");
    }

    for (int i=0; i<num_hw_components; i++) {
        printf("  Component name: %d\n", dbcomponent[i].number);
        printf("  Component name: %s\n", dbcomponent[i].name);
        printf("Quantity on hand: %d\n", dbcomponent[i].on_hand);
        fputc('\n', stdout);
    }
}

/* Cerca un articolo nel vettore dbcomponent, restituisce l'indice del vettore
qualora la ricerca fosse positiva, EXIT_FAILURE altrimenti */
int find_component(int num) {
    for (int i=0; i<num_hw_components; i++)
        if (dbcomponent[i].number == num)
            return i;

    return (-1);
}
