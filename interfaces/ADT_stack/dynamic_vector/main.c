#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
    Stack st1, st2;
    int st_size = 10, val;

    // Imposta l'ampiezza massima di entrambi gli stack a 10
    st1 = create(st_size);
    st2 = create(st_size);

    // Riempie entrambi gli stack
    for (int i=0; i<st_size; i++) {
        push(st1, i+i);
        push(st2, i*i);
    }

    val = pop(st1);
    printf("popped %d from st1 Stack\n", val);
    val = pop(st1);
    printf("popped %d from st1 Stack\n", val);
    val = pop(st2);
    printf("popped %d from st2 Stack\n", val);

    destroy(st1);

    while (!is_empty(st2))
        printf("popped %d from st2 Stack\n", pop(st2));

    make_empty(st2);
    printf("popped %d from st2 Stack\n", pop(st2));

    push(st2, 100);

    if (is_empty(st2))
        fputs("st2 is empty\n", stdout);
    else
        fputs("st2 is not empty\n", stdout);
    
    destroy(st2);

    return(EXIT_SUCCESS);
}
