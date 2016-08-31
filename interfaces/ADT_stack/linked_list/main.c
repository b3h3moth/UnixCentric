#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
    Stack st1 = create();

    for (int i=0; i<10; i++)
        push(st1, i);
    
    printf("pop: %d from stack\n", pop(st1));
    printf("pop: %d from stack\n", pop(st1));
    printf("pop: %d from stack\n", pop(st1));
    printf("pop: %d from stack\n", pop(st1));

    print_stack(st1);

    make_empty(st1);

    return(EXIT_SUCCESS);
}
