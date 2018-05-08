#include "polish.h"

void fill(stack *stk, const char *str)
{
   const char   *p = str;
   char         c1, c2;
   boolean      b1, b2;
   data         d;
   stack        tmp;
  
   initialize(stk);
   initialize(&tmp);
   /*
   // First process the string and push data on tmp.
   */
   while (*p != '\0') {
      while (isspace(*p) || *p == ',')
         ++p;
      b1 = (boolean) ((c1 = *p) == '+' || c1 == '-' || c1 == '*');
      b2 = (boolean) ((c2 = *(p + 1)) == ',' || c2 == '\0');
      if (b1 && b2) {
         d.kind = operator;
         d.u.op = c1;
      }
      else {
         d.kind = value;
         assert(sscanf(p, "%d", &d.u.val) == 1);
      }
      if (!full(&tmp))
         push(d, &tmp);               /* push data on tmp */
      while (*p != ',' && *p != '\0')
         ++p;
   }
   /*
   // Now pop data from tmp and push on stk.
   */
   while (!empty(&tmp)) {
      d = pop(&tmp);                  /* pop data from tmp */
      if (!full(stk))
         push(d, stk);                /* push data on stk */
   }
}
