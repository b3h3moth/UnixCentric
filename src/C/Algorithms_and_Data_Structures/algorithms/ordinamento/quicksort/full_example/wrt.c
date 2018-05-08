#include "quicksort.h"

void wrt(char *s, int *a, int n)
{
   int   i;

   printf("\n%s\n%s%s\n", "---", s, ":");
   for (i = 0; i < n; ++i) {
      if (i % 10 == 0)
         putchar('\n');
      printf("%7d", a[i]);
   }
   if (n % 10 != 0)
      putchar('\n');
}
