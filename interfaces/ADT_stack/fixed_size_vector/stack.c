#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// ADT STack - Fixed vector representation

#define STACK_SIZE 50

struct stack_type {
    Item contents[STACK_SIZE];
    int top;
};

// Stampa un messaggio qualora dovessero esserci problemi con pop() o push()
static void terminate(const char *msg) {
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

// Alloca la memoria necessaria a contenere Stack
Stack create(void) {
    Stack s = malloc(sizeof(Stack));

    if (s == NULL)
        terminate("Err. creating Stack");
    s->top = 0;
    return s;
}

// Rilascia la memoria dello Stack
void destroy(Stack s) {
    free(s);
}

// Svuota lo stack
void make_empty(Stack s) {
    s->top = 0;
}

// Verifica se lo stack e' vuoto
bool is_empty(Stack s) {
    return (s->top == 0);
}

// Verifica se lo stack e' pieno
bool is_full(Stack s) {
    return (s->top == STACK_SIZE);
}

// Inserisce un elemento (intero) nello stack
void push(Stack s, Item val) {
    if (is_full(s))
        terminate("Err: push() - stack is full");

    s->contents[s->top++] = val;
}

// Rimuove un elemento dallo stack
Item pop(Stack s) {
    if (is_empty(s))
        terminate("Err: pop() - stack is empty");

    return (s->contents[--s->top]);
}
