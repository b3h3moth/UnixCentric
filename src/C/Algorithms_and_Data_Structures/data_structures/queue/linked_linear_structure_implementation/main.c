#include <stdio.h>
#include <stdlib.h>
#include "type_queue.h"

int main(void) {
    typeQueue_LLS *myqq = init();

    if (emptyQueue(*myqq))
        printf("The queue is empty\n");
    else
        printf("The queue is not empty\n");

    return(EXIT_SUCCESS);
}
