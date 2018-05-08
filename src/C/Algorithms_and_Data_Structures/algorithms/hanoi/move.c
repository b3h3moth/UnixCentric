#include "hanoi.h"

void move(int n, char a, char b, char c)
{
   if (n == 1) {
      ++cnt;
      printf("%5d: %s%d%s%c%s%c.\n", cnt,
         "Move disk ", 1, " from tower ", a, " to tower ", c);
   }
   else {
      move(n - 1, a, c, b);
      ++cnt;
      printf("%5d: %s%d%s%c%s%c.\n", cnt,
         "Move disk ", n, " from tower ", a, " to tower ", c);
      move(n - 1, b, a, c);
   }
}
