#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct person {
    char firstname[16];
    char lastname[16];
    int age;
};

typedef struct person Person;

/* Constant PersonError is useful when an error occurs */
Person PersonError = {"","",0};

/* Print full person */
void print(Person p) {
    printf("%s %s, %d years old\n", p.firstname, p.lastname, p.age);
}

/* Two structure person (or two persons) are equals */
int equal(Person p1, Person p2) {
    return (strcmp(p1.firstname, p2.firstname) == 0) &&
           (strcmp(p1.lastname, p2.lastname) == 0) && (p1.age == p2.age);
}

int main() {
    return(EXIT_SUCCESS);
}
