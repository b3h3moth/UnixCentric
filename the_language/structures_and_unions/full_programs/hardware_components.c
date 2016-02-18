#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"
#include "hardware_components.h"

static int find_component(int num);

// Il numero dei componenti hardware memorizzati
int num_hw_components = 0;

// Il database dei componenti e' un vettore di strutture
HardwareItem dbcomponent[MAX_COMPONENTS];

/* Inserisce un componente nel database; nel caso fosse gia' presente nel db 
opppure il db stesso fosse pieno restituisce un messaggio di errore */
int insert(void) {
    int component_id;

    if (num_hw_components == MAX_COMPONENTS) {
        printf("DB is full\n");
        return(1);
    }

    printf("Enter component id: ");
    scanf("%d", &component_id);

    // Verifica se un componente gia' esiste
    if (find_component(component_id) >= 0) {
        printf("Component already exists.\n");
        return(1);
    }
    dbcomponent[num_hw_components].id = component_id;

    printf("Enter component name: ");
    read_line(dbcomponent[num_hw_components].name, MAX_LEN);

    printf("Enter model name: ");
    read_line(dbcomponent[num_hw_components].model, MAX_LEN);

    printf("Enter quantity: ");
    scanf("%d", &dbcomponent[num_hw_components].quantity);

    return num_hw_components++;
}

void delete(void) {
    int i, num;

    printf("Enter component id: ");
    scanf("%d", &num);
    
    i = find_component(num);

    // Se si intende rimuovere il primo elemento dell'array
    if ((i == 0) && (num_hw_components == 1))
        num_hw_components = 0;
    else if (i == num_hw_components-1) { // rimozione ultimo elemento array
        num_hw_components--;
    } else if (i < 0)
        fprintf(stderr, "Sorry, request component doesn't exist\n");
    else if (num_hw_components == 0)
        fprintf(stderr, "Sorry, db is empty.\n");
}

/* Verifica il numero di componente, se non esiste stampa un messaggio di 
errore, in caso contrario modifica la quantita' disponibile */
void update(void) {
    int i, num, change;

    printf("Enter component id: ");
    scanf("%d", &num);

    i = find_component(num);

    if (i >= 0) {
        printf("Enter quantity to change: ");
        scanf("%d", &change);
        dbcomponent[i].quantity += change;
    } else 
        printf("Component not found.\n");
}

// Cerca un componente nel db
void search(void) {
    int i, num;

    printf("Enter component id: ");
    scanf("%d", &num);

    i = find_component(num);

    if (i >= 0) {
        printf("Component name: %s\n", dbcomponent[i].name);
        printf("      Quantity: %d\n", dbcomponent[i].quantity);
        printf("         Model: %s\n", dbcomponent[i].model);
    } else
        printf("Component not found.\n");
}

// Stampa la lista dei componenti hardware
void print(void) {
    if (num_hw_components <= 0) {
        printf("List of hardware components is empty.\n");
}

    for (int i=0; i<num_hw_components; i++) {
        printf("  Component id: %d\n", dbcomponent[i].id);
        printf("Component name: %s\n", dbcomponent[i].name);
        printf("      Quantity: %d\n", dbcomponent[i].quantity);
        printf("         Model: %s\n", dbcomponent[i].model);
        fputc('\n', stdout);
    }
}

/* Cerca un articolo nel vettore dbcomponent, restituisce l'indice del vettore
- quindi un intero maggiore o uguale a zero - in caso di successo, 
-1 altrimenti. */
static int find_component(int num) {
    for (int i=0; i<num_hw_components; i++)
        if (dbcomponent[i].id == num)
            return i;

    return (-1);
}
