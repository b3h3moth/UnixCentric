#ifndef HARDWARE_COMPONENTS_H
#define HARDWARE_COMPONENTS_H

#define MAX_LEN 25
#define MAX_COMPONENTS 100  // Componenti Hardware

// La struttura di ciascuna voce del catalogo
struct hw_item {
    int id;
    char name[MAX_LEN+1];
    char model[MAX_LEN+1];
    int quantity;
}; 

typedef struct hw_item HardwareItem; 

// Prototipi di funzione
int insert(void);
void update(void);
void search(void);
void delete(void);
void print(void);

#endif
