#include <stdio.h>
#include <stdlib.h>

#define ROWS    2
#define COLS    3

int main(void) {
    
    int data[ROWS][COLS] = {
        {10, 20, 30},   // Row 1
        {40, 50, 60},   // Row 2
    };

    /* Stampano l'indirizzo iniziale dell'array multidimensionale o del primo
    elemento  */
    printf("          data: %p\n", (void *)data);
    printf("      &data[0]: %p\n", (void *)&data[0]);
    printf("       data[0]: %p\n", (void *)data[0]);
    printf("         &data: %p\n", (void *)&data);
    printf("         *data: %p\n", (void *)*data);
    printf("     *&data[0]: %p\n", (void *)*&data[0]);
    printf("        *&data: %p\n", (void *)*&data);
    printf("   &data[0][0]: %p\n", (void *)&data[0][0]);

    // Stampano il valore del primo elemento del primo sottoarray, [0][0]
    printf("      *data[0]: %d\n", *data[0]);
    printf("  *&data[0][0]: %d\n", *&data[0][0]);

    // Stampa l'indirizzo del primo elemento del secondo sottoarray
    printf("     *(data+1): %p\n", (void *)*(data +1));
    
    // Stampa il valore del primo elemento del secondo sottoarray [1][0]
    printf("  *(*(data+1)): %d\n", *(*(data + 1)));

    // Stampa l'indirizzo del secondo elemento del secondo sottoarray [1][1]
    printf("   *(data+1)+1: %p\n", (void *)(*(data + 1) + 1));

    // Stampa il valore del secondo elemento del secondo sottoarray [1][1]
    printf("*(*(data+1)+1): %d\n", *(*(data + 1) + 1) );
  
    printf("\n Array elements:\n");
    int *ptr;
    unsigned short new_line = 1;

    /* Stampa ciascun elemento dell'array, il ciclo for e' gestito ovviamente
    solo mediante puntatori */
    for (ptr = &data[0][0]; ptr <= &data[ROWS-1][COLS-1]; ptr++, new_line++) {
        printf("%d, ", *ptr);

        // Just a trick to get a new-line for each row
        if (new_line % COLS == 0)
            printf("\n");
    }

    printf("\n Row elements:\n");
    // Stampa solo gli elementi della prima riga
    for (ptr = data[0]; ptr<data[0] + COLS; ptr++)
        printf("%d, ", *ptr);

    return(EXIT_SUCCESS);
}
