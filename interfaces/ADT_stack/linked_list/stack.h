#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void print_stack_elements(void);
void push(int val);
int pop(void);

#endif
