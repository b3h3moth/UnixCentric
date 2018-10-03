#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct person Person;
typedef struct node_lls NodeLLS; /* LLS stands for Linear Linked Structure */
typedef struct type_lls TypeLLS;

struct person {
    char firstname[16];
    char lastname[16];
    int age;
};

struct node_lls {
    Person info;
    NodeLLS *next;
};

struct type_lls {
    NodeLLS *head;  /* Pointer to the first element of the LLS */
    int size;       /* How many nodes the LLS contains */
};

/* Constant PersonError is useful when an error occurs */
Person PersonError = {"","",0};

/* Function prototypes: on Person */
void printPerson(Person p);
int equal(Person p1, Person p2);
/* Function prototypes: on LLS */
TypeLLS *init();
int empty(TypeLLS *l);
TypeLLS *add(TypeLLS *l, Person p);
TypeLLS *del(TypeLLS *l);
Person printFirst(TypeLLS *l);
void print(TypeLLS *l);

int main(void) {
    TypeLLS *t = init();
    Person newperson = { "Richard", "Stallman", 65};
    Person newcpy;

    if (empty(t))
        printf("The LLS is empty\n");

    t = add(t, newperson);
    print(t);
    t = del(t);
    print(t);

    return(EXIT_SUCCESS);
}

/* Print full person */
void printPerson(Person p) {
    printf("%s %s, %d years old\n", p.firstname, p.lastname, p.age);
}

/* Two structure person (or two persons) are equals */
int equal(Person p1, Person p2) {
    return (strcmp(p1.firstname, p2.firstname) == 0) &&
           (strcmp(p1.lastname, p2.lastname) == 0) && (p1.age == p2.age);
}

/* LLS initialization */
TypeLLS *init() {
    TypeLLS *h = (TypeLLS *) malloc(sizeof(TypeLLS));
    h->head = NULL;
    h->size = 0;
    return h;
}

/* Check if the LLS is empty */
int empty(TypeLLS *l) {
    return l->size == 0;    /* or: return l->head == NULL; */
}

/* Add a Person on the head of the list */
TypeLLS *add(TypeLLS *l, Person p) {
    TypeLLS *new = init();
    new->head = (NodeLLS*) malloc(sizeof(NodeLLS));
    new->head->info = p;                            /* copy each member of p */
    new->head->next = l->head;                      /* link previous node */
    new->size = l->size + 1;
    return new;
}

/* Remove a Person from the head of the list */
TypeLLS *del(TypeLLS *l) {
    if (l->size == 0)
        return l;
    else {
        TypeLLS *temp = init();
        temp->head = l->head->next;
        temp->size = l->size - 1;
        return temp;
    }
}

/* Returns the first element */
Person printFirst(TypeLLS *l) {
    if (l->size == 0)
        return PersonError;
    else
        return l->head->info;
}

/* Print each node */
void print(TypeLLS *l) {
    NodeLLS *n = l->head;
    while (n != NULL) {
        printPerson(n->info);
        n = n->next;
    }
}
