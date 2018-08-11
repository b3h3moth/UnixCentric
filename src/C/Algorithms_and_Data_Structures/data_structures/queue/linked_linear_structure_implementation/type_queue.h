#ifndef TYPE_QUEUE_H
#define TYPE_QUEUE_H

typedef struct node_LLS node_LLS;
typedef struct typeQueue_LLS typeQueue_LLS;

struct node_LLS {
    int data;
    node_LLS *next;
};

struct typeQueue_LLS {
    node_LLS *head;
    node_LLS *tail;
};


/* Queue data structure, Linked Linear Structure (LLS) implementation.
- A pointer to node_LLS 'head' is a pointer to the generator node;
- A pointer to node_LLS 'tail' is a pointer to the last node;
- Each node (node_LLS) includes:
    - the filed data, to save an integer value:
    - the field next, a pointer to the next node of the queue.
*/

typeQueue_LLS *init(void);
int emptyQueue(typeQueue_LLS q);
void printQueue(typeQueue_LLS q);
void putElemToQueue(typeQueue_LLS *q, int val);

#endif
