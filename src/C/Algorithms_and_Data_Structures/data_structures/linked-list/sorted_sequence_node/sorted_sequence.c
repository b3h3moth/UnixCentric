#include <stdlib.h>
#include "sorted_sequence.h"

sorted_Sequence *init(void) {
    sorted_Sequence *s = (sorted_Sequence*)malloc(sizeof(sorted_Sequence));
    s->head = (sorted_Sequence_Node*)malloc(sizeof(sorted_Sequence_Node));
    s->head->next = NULL; /* Node generator */
}