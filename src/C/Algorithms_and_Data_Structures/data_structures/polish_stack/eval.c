/* Evaluation of the Polish stack. */

#include "polish.h"

int evaluate(stack *polish)
{
   data    d, d1, d2;
   stack   eval;

   initialize(&eval);
   while (!empty(polish)) {
      d = pop(polish);
      switch (d.kind) {
      case value:
         push(d, &eval);
         break;
      case operator:
         d2 = pop(&eval);
         d1 = pop(&eval);
         d.kind = value;         /* begin overwriting d */
         switch (d.u.op) {
         case '+':
            d.u.val = d1.u.val + d2.u.val;
            break;
         case '-':
            d.u.val = d1.u.val - d2.u.val;
            break;
         case '*':
            d.u.val = d1.u.val * d2.u.val;
         }
         push(d, &eval);
      }
   }
   d = pop(&eval);
   return d.u.val;
}
