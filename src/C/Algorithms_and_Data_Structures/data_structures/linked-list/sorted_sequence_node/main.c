#include <stdio.h>
#include <stdlib.h>
#include "sorted_sequence.h"

/* The goal of "Sorted Sequence Node" (from now SSN) ADT is to keep all element
   sorted all time. */

int main() {
    /* Initialize the SSN to NULL */
    sorted_Sequence *ssn = init();
    /* Add the first node */
    ins_First(ssn, 15);
    printf("%d\n", ssn->head->next->data);

    return(EXIT_SUCCESS);
}
