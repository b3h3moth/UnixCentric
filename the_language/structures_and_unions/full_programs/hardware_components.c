#include <stdio.h>
#include <stdlib.h>
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
    scanf("%d", &dbcomponent[num_hw_components].quantity);

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
        dbcomponent[i].quantity += change;
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
        printf("Component name: %s\n", dbcomponent[i].name);
        printf("      Quantity: %d\n", dbcomponent[i].quantity);
    } else
        printf("Component not found.\n");
}

// Stampa la lista dei componenti hardware
void print(void) {
    if (num_hw_components <= 0) {
        printf("List of hardware components is empty.\n");
    }

    for (int i=0; i<num_hw_components; i++) {
        printf("Component name: %d\n", dbcomponent[i].number);
        printf("Component name: %s\n", dbcomponent[i].name);
        printf("      Quantity: %d\n", dbcomponent[i].quantity);
        fputc('\n', stdout);
    }
}

/* Cerca un articolo nel vettore dbcomponent, restituisce l'indice del vettore
qualora la ricerca fosse positiva, EXIT_FAILURE altrimenti */
static int find_component(int num) {
    for (int i=0; i<num_hw_components; i++)
        if (dbcomponent[i].number == num)
            return i;

    return (-1);
}
