#include <stdlib.h>
#include "type_queue.h"

/* Queue initialization */
typeQueue_LLS *init() {
    typeQueue_LLS *q = (typeQueue_LLS *)malloc(sizeof(typeQueue_LLS));
    node_LLS *n = (node_LLS *)malloc(sizeof(node_LLS));
    q->head = n;        /* The head and the tail of the queue... */
    q->tail = n;        /* ...point to the same node. */
    n->next = NULL;     /* the generator node. Now the queue is empty. */
}
