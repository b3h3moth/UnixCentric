#include "quicksort.h"

void quicksort(int *left, int *right)
{
   int   *p, pivot;

   if (find_pivot(left, right, &pivot) == yes) {
      p = partition(left, right, pivot);
      quicksort(left, p - 1);
      quicksort(p, right);
   }
}
