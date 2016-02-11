#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

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

int find(int num);
int insert(void);
void search(void);
void update(void);
void print(void);

int main(void) {
    return(EXIT_SUCCESS);
}
