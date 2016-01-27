#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef int Item;
typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item val);
Item pop(Stack s);
void print_stack(Stack s);

#endif
