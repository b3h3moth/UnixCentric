/* The basic stack routines. */

#include "polish.h"

void initialize(stack *stk)
{
   stk -> cnt = 0;
   stk -> top = NULL;
}

void push(data d, stack *stk)
{ 
   elem   *p;

   p = malloc(sizeof(elem));
   p -> d = d;
   p -> next = stk -> top;
   stk -> top = p;
   stk -> cnt++;
}

data pop(stack *stk)
{ 
   data   d;
   elem   *p;

   d = stk -> top -> d;
   p = stk -> top;
   stk -> top = stk -> top -> next;
   stk -> cnt--;
   free(p);
   return d;
}

data top(stack *stk)
{ 
   return (stk -> top -> d);
}

boolean empty(const stack *stk)
{ 
   return ((boolean) (stk -> cnt == EMPTY));
}

boolean full(const stack *stk)
{ 
   return ((boolean) (stk -> cnt == FULL));
}
