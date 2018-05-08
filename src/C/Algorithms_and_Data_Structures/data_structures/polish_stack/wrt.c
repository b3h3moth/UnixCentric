#include "polish.h"

void wrt_data(data *dp)
{
   switch (dp -> kind) {
   case operator:
      printf("%s%3c\n",
         "kind: operator      op:", dp -> u.op);
      break;
   case value:
      printf("%s%3d\n",
         "kind: value        val:", dp -> u.val);
   }
}

void wrt_stack(stack *stk)
{
   data   d;

   printf("stack count:%3d%s",
      stk -> cnt, (stk -> cnt == 0) ? "\n" : "     "); 
   if (!empty(stk)) {
      d = pop(stk);         /* pop the data */
      wrt_data(&d);         /* print the data */
      wrt_stack(stk);       /* recursive call */
      push(d, stk);         /* push the data */
   }
}
