#include <stdio.h>
#include <stdlib.h>

struct db {
    int id;
    int year;
    int age;
};

int main(void) {
    // Inizializzazione di una struttura con un compound literals
    struct db data = (struct db){1, 2000, 30};

    printf("id: %d\tyear: %d\tage: %d\n", data.id, data.year, data.age);

    // E' possibile anche utilizzare un compund literal per come costante
    data.id = (const int){2};
    data.year = (const int){2016};
    data.age = (const int){20};

    printf("id: %d\tyear: %d\tage: %d\n", data.id, data.year, data.age);
    
    return(EXIT_SUCCESS);
}
