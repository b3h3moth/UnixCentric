#include <stdlib.h>
#include "sorted_sequence.h"

/* SSN initialization */
sorted_Sequence *init(void) {
    sorted_Sequence *s = (sorted_Sequence*)malloc(sizeof(sorted_Sequence));
    s->head = (sorted_Sequence_Node*)malloc(sizeof(sorted_Sequence_Node));
    s->head->next = NULL; /* Node generator */
    return s;
}

/* Add a node in the first position of the SSN */
void ins_First(sorted_Sequence *s, int val) {
    sorted_Sequence_Node *n = (sorted_Sequence_Node*)malloc(sizeof(sorted_Sequence_Node));
    n->data = val;
    n->next = s->head->next;
    s->head->next = n;
}

/* Add a node in the sorted sequence */
void ins_Sort(sorted_Sequence *s, int val) {
    sorted_Sequence_Node *p = s->head;
    while ((p->next != NULL) && p->next->data < val)
        p = p->next;
    sorted_Sequence_Node *n = (sorted_Sequence_Node*)malloc(sizeof(sorted_Sequence_Node));
    n->data = val;
    n->next = p->next;
    p->next = n;
}
