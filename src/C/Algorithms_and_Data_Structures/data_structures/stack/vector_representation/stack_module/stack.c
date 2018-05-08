#include "stack.h"

void reset(stack *stk)
{
   stk -> top = EMPTY;
}

void push(char c, stack *stk)
{
   stk -> top++;
   stk -> s[stk -> top] = c;
}

char pop(stack *stk)
{
   return (stk -> s[stk -> top--]);
}

char top(const stack *stk)
{
   return (stk -> s[stk -> top]);
}

_Bool empty(const stack *stk)
{
   return ((_Bool) (stk -> top == EMPTY));
}

_Bool full(const stack *stk)
{
   return ((_Bool) (stk -> top == FULL));
}
