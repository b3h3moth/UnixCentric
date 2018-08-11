#include <stdio.h>
#include <stdlib.h>
#include "type_queue.h"

/* Queue initialization */
typeQueue_LLS *init(void) {
    typeQueue_LLS *q = (typeQueue_LLS *)malloc(sizeof(typeQueue_LLS));
    node_LLS *n = (node_LLS *)malloc(sizeof(node_LLS));
    q->head = n;        /* The head and the tail of the queue... */
    q->tail = n;        /* ...point to the same node. */
    n->next = NULL;     /* the generator node. Now the queue is empty. */
    return q;
}

/* Check if the queue is empty */
int emptyQueue(typeQueue_LLS q) {
    return q.head->next == NULL;
}

/* Print each element of the queue */
void printQueue(typeQueue_LLS q) {
    node_LLS *n = q.head->next;
    while (n != NULL) {
        printf("%d, ", n->data);
        n = n->next;
    }
}

/* Add an element to the queue */
void putElemToQueue(typeQueue_LLS *q, int val) {
    node_LLS *n = (node_LLS*)malloc(sizeof(node_LLS));
    n->data = val;
    n->next = NULL;
    q->tail->next = n;
    q->tail = n;
}
