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

int main(void) {
    return(EXIT_SUCCESS);
}
