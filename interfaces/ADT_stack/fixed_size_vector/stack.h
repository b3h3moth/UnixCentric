# ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Tipo di dato salvato nello stack, puo' essere cambiato con qualsiasi cosa
typedef int Item;
typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item val);
Item pop(Stack s);

#endif
