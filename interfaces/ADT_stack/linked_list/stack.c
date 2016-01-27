#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Linked List Stack representation

struct node {
    int data;
    struct node *next;
};

static struct node *top = NULL;

// Stampa un messaggio qualora dovessero esserci problemi con pop() o push()
static void terminate(const char *msg) {
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

// Svuota lo stack
void make_empty(void) {
    while (!is_empty())
        pop();
}

// Verifica se lo stack e' vuoto
bool is_empty(void) {
    return (top == NULL);
}

// Verifica se lo stack e' pieno
bool is_full(void) {
    return false;
}

// Stampa ciascun elemento dello stack
void print_stack_elements(void) {
    struct node *temp;

    if (is_empty())
        terminate("Err: print_stack_elements() - Sorry, stack is empty");

    temp = top;

    while (temp) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Inserisce un elemento (intero) nello stack
void push(int val) {
    struct node *temp = malloc(sizeof(struct node));

    if (temp == NULL)
        terminate("Err: push() - stack is full");

    temp->data = val;
    temp->next = top;   // Inizialmente top e' uguale a NULL
    top = temp;
}

// Rimuove un elemento dallo stack
int pop(void) {
    struct node *old;
    int val;

    if (is_empty())
        terminate("Err: pop() - stack is empty");

    old = top;
    val = top->data;
    top = top->next;
    free(old);
    return val;
}
