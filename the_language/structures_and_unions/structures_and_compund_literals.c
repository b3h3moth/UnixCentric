#include <stdio.h>
#include <stdlib.h>

struct db {
    int id;
    int year;
    int age;
};

int main(void) {
    // Inizializzazione di una struttura con un compound literals
    struct db data = (struct db){1, 2016, 30};

    printf("id: %d\nyear: %d\nage: %d\n", data.id, data.year, data.age);

    return(EXIT_SUCCESS);
}
