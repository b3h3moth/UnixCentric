#include <stdio.h>
#include <stdlib.h>
#include "type_queue.h"

int main(void) {
    int i;
    int val = -1;
    typeQueue_LLS *myqq = init();

    for (i = 1; i<10; i++)
        putElemToQueue(myqq, i*i);

    printQueue(*myqq);

    printf("\n");

    for (i = 1; i<10; i++) {
        val = getElemFromQueue(myqq);
        printf("The first elemment of the queue is: %d\n", val);
        if (emptyQueue(*myqq)) {
            printf("The queue is empty\n");
            break;
        }
    }

    free(myqq);

    return(EXIT_SUCCESS);
}
