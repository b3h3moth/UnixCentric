#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
    for (int i=0; i<10; i++)
        push(i);
    
    // Rimuove 9
    pop();
    // Rimuove 8
    pop();
    // Rimuove 7
    pop();

    print_stack_elements();

    make_empty();

    print_stack_elements();
    
    return(EXIT_SUCCESS);
}
