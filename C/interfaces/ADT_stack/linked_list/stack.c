#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Linked List Stack representation

struct node {
    Item data;
    struct node *next;
};

// Puntatore al primo nodo della lista 
struct stack_type {
    struct node *top;
};

// Stampa un messaggio qualora dovessero esserci problemi con pop() o push()
static void terminate(const char *msg) {
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

// Alloca la memoria necessaria per la struttura stack_type
Stack create() {
    Stack s = malloc(sizeof(struct stack_type));

    if (s == NULL)
        terminate("Err. I couldn't create stack, sorry");

    s->top = NULL;

    return s;
}

// Rilascia la memoria dello Stack
void destroy(Stack s) {
    make_empty(s);
    free(s);
}

// Svuota lo stack
void make_empty(Stack s) {
    while (!is_empty(s))
        pop(s);
}

// Verifica se lo stack e' vuoto
bool is_empty(Stack s) {
    return (s->top == NULL);
}

// Verifica se lo stack e' pieno
bool is_full(Stack s) {
    return false;
}

// Inserisce un elemento (intero) nello stack
void push(Stack s, Item val) {
    struct node *temp = malloc(sizeof(struct node));

    if (temp == NULL)
        terminate("Err: push() - stack is full");

    temp->data = val;
    temp->next = s->top; 
    s->top = temp;
}

// Rimuove un elemento dallo stack
Item pop(Stack s) {
    struct node *old;
    Item val;

    if (is_empty(s))
        terminate("Err: pop() - stack is empty");

    old = s->top;
    val = old->data;
    s->top = old->next;
    free(old);
    return val;
}

void print_stack(Stack s) {
    struct node *temp = malloc(sizeof(struct node));

    if (is_empty(s))
        terminate("Stack is empty");

    temp = s->top;

    while (temp) {
        printf("%d\n",  temp->data);
        temp = temp->next;
    }
}
