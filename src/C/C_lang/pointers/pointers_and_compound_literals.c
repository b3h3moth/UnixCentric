#include <stdio.h>
#include <stdlib.h>

struct db {
    int id;
    int year;
};

int main(void) {
    // Inizializzazione del puntatore 'ptr' al primo elemento dell'array
    int *ptr = (int []){10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    while(*ptr > 0) {
        printf("%3d\n", *ptr);
        ptr++;
    }

    // Un compund literal per l'inizializzazione di un puntatore a struttura
    struct db *data = &(struct db){1, 2016};

    printf("id: %d\tyear: %d\n", data->id, data->year);

    return(EXIT_SUCCESS);
}
