#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Vector Stack representation

#define STACK_SIZE 50

static int contents[STACK_SIZE];
static int top = 0;

// Stampa un messaggio qualora dovessero esserci problemi con pop() o push()
static void terminate(const char *msg) {
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

// Svuota lo stack
void make_empty(void) {
    top = 0;
}

// Verifica se lo stack e' vuoto
bool is_empty(void) {
    return (top == 0);
}

// Verifica se lo stack e' pieno
bool is_full(void) {
    return (top == STACK_SIZE);
}

// Stampa ciascun elemento dello stack
void print_stack_elements(void) {
    if (is_empty())
        terminate("Err: print_stack_elements() - Sorry, stack is empty");

    while (top-- != 0)
        printf("%d\n", contents[top]);
}

// Inserisce un elemento (intero) nello stack
void push(int val) {
    if (is_full())
        terminate("Err: push() - stack is full");

    contents[top++] = val;
}

// Rimuove un elemento dallo stack
int pop(void) {
    if (is_empty())
        terminate("Err: pop() - stack is empty");

    return (contents[--top]);
}
