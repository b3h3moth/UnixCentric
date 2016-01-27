#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// ADT STack - Dynamic vector representation

struct stack_type {
    Item *contents;     // vettore dinamico (lo stack)
    int top;            // testa dello stack
    int size;           // ampiezza massima del vettore dinamico
};

// Stampa un messaggio qualora dovessero esserci problemi con pop() o push()
static void terminate(const char *msg) {
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

/* Alloca la memoria necessaria per la struttura stack_type (ADT) e per il 
vettore dinamico che conterra' gli elementi dello stack */
Stack create(int size) {
    Stack s = malloc(sizeof(struct stack_type));

    if (s == NULL)
        terminate("Err. I couldn't create stack, sorry");

    s->contents = malloc(size * sizeof(Item));

    if (s->contents == NULL) {
        free(s);
        terminate("Err. I couldn't create stack, sorry");
    }

    s->top = 0;
    s->size = size;

    return s;
}

// Rilascia la memoria dello Stack
void destroy(Stack s) {
    free(s->contents);
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
    return (s->top == s->size);
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
