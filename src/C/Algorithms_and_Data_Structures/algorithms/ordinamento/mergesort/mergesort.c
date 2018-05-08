/*
// Mergesort: Use merge() to sort an array of size n.
*/

#include "mergesort.h"

void   merge(int *, int *, int *, int, int);

void mergesort(int key[], int n)
{ 
   int    j, k, m, *w;

   for (m = 1; m < n; m *= 2)
      ;
   if (m != n) {
      printf("ERROR: Size of the array is not a power of 2 - bye!\n");
      exit(1);
   }
   w = calloc(n, sizeof(int));                /* allocate workspace */
   for (k = 1; k < n; k *= 2) {
      for (j = 0; j < n - k; j += 2 * k)
         merge(key + j, key + j + k, w + j, k, k);  /* merge into w */
      for (j = 0; j < n; ++j)
         key[j] = w[j];                    /* write w back into key */
   }
   free(w);                                   /* free the workspace */
}
