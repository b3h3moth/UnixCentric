#include "mergesort.h"

int main(void)
{
   int   i, key[] = { 4, 3, 1, 67, 55, 8, 0, 4,
                     -5, 37, 7, 4, 2, 9, 1, -1 };

   mergesort(key, KEYSIZE);
   printf("After mergesort:\n");
   for (i = 0; i < KEYSIZE; ++i)
      printf("%4d", key[i]);
   putchar('\n');
   return 0;
}
