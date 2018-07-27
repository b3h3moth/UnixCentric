#include <stdio.h>
#include <stdlib.h>
#include "type_queue.h"

int main(void) {
    int i;
    typeQueue_LLS *myqq = init();

    for (i = 0; i<10; i++)
        insQueue(myqq, i*i);

    if (emptyQueue(*myqq))
        printf("The queue is empty\n");
    else
        printQueue(*myqq);

    return(EXIT_SUCCESS);
}
