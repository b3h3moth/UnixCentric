#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct person Person;
typedef struct node_lls NodeLLS;
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
    NodeLLS *head;  /* Pointer to the first element of the Linear Linked List */
    int size;       /* How many nodes the Linked Linear Structure contains */
};

/* Constant PersonError is useful when an error occurs */
Person PersonError = {"","",0};

/* Function prototypes */
void print(Person p);
int equal(Person p1, Person p2);

int main() {
    return(EXIT_SUCCESS);
}

/* Print full person */
void print(Person p) {
    printf("%s %s, %d years old\n", p.firstname, p.lastname, p.age);
}

/* Two structure person (or two persons) are equals */
int equal(Person p1, Person p2) {
    return (strcmp(p1.firstname, p2.firstname) == 0) &&
           (strcmp(p1.lastname, p2.lastname) == 0) && (p1.age == p2.age);
}
