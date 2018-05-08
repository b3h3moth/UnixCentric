/* A linked list implementation of a Polish stack. */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define   EMPTY      0
#define   FULL       10000

struct data {
   enum {operator, value}   kind;
   union {
      char   op;
      int    val;
   }                        u;
};

typedef   struct data          data;
typedef   enum {false, true}   boolean;

struct elem {                   /* an element on the stack */
   data          d;
   struct elem   *next;
};

typedef   struct elem   elem;

struct stack {
   int    cnt;                  /* a count of the elements */
   elem   *top;                 /* ptr to the top element */
};

typedef   struct stack   stack;

boolean   empty(const stack *stk);
int       evaluate(stack *polish);
void      fill(stack *stk, const char *str);
boolean   full(const stack *stk);
void      initialize(stack *stk);
data      pop(stack *stk);
void      wrt_data(data *dp);
void      wrt_stack(stack *stk);
void      push(data d, stack *stk);
data      top(stack *stk);
