#include <stdio.h>
#include <stdlib.h>
#include "sorted_sequence.h"

/* The purpose of "Sorted Sequence Node" (SSN) ADT is to keep all elements
   sorted all time. */

int main() {
    /* Initialize the SSN to NULL */
    sorted_Sequence *ssn = init();
    /* Add the first node */
    ins_First(ssn, 15);

    /* For debugging purpose: print integer in the first node */
#ifdef DBG
    printf("%d\n", ssn->head->next->data);
#endif

    return(EXIT_SUCCESS);
}
