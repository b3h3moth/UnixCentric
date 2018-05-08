#include <stdlib.h>
#include "quicksort.h"

int main(void) {
    int a[N], i;

    // Seed the random number generator.
    srand(time(NULL));

    // Put randomly distributed values in a[].
    for (i = 0; i < N; ++i)
        a[i] = rand() % 1000;
    
    // Write a[] before and after sorting.
    wrt("Before", a, N);
    
    quicksort(a, a + N - 1);
    
    wrt("After", a, N);
    
    return(EXIT_SUCCESS);
}
