#include "quicksort.h"

yes_no find_pivot(int *left, int *right, int *pivot_ptr)
{
   int   a, b, c, *p;

   a = *left;                                 /* left value */
   b = *(left + (right - left) / 2);        /* middle value */
   c = *right;                               /* right value */
   o3(a, b, c);                     /* order these 3 values */
   if (a < b) {         /* pivot will be higher of 2 values */
      *pivot_ptr = b;
      return yes;
   }
   if (b < c) {
      *pivot_ptr = c;
      return yes;
   }
   for (p = left + 1; p <= right; ++p)
      if (*p != *left) {
       *pivot_ptr = (*p < *left) ? *left : *p;
       return yes;
      }
   return no;           /* all elements have the same value */
}
