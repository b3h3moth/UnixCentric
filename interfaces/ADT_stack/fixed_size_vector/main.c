#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
    Stack st1, st2;
    int val;

    st1 = create();
    st2 = create();
    
    push(st1, 10);
    push(st2, 1);
    push(st1, 20);
    push(st2, 2);
    push(st1, 30);
    push(st2, 3);
    push(st1, 40);
    push(st2, 4);

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
