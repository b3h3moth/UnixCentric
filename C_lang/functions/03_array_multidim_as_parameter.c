#include <stdio.h>
#include <stdlib.h>

// Lunghezza di righe e colonne dell'array multidimensionale
#define ROWS 3
#define COLS 3

// Prototipo
int find_elem(int data[][COLS], int value);

/* L'array multidimensionale, sia nel prototipo sia nella dichiarazione della
funzione deve essere inserito col doppio operatore di subscript [][]. La regola
generale dice che la prima dimensione puo' essere omessa, mentre quelle 
successive sono obbligatorie */

int main(void) {
    int data[ROWS][COLS] = {
        {10, 20, 30}, 
        {40, 50, 60},
        {70, 80, 90}
    };

    int result = find_elem(data, 8);

    if (result == -1)
        printf("Not found\n");
    else
        printf("%d\n", result);

    return(EXIT_SUCCESS);
}

int find_elem(int data[][COLS], int value) {
    int temp = -1;

    for (int rs = 0; rs < ROWS; rs++) {     // Righe
        for (int cs = 0; cs < COLS; cs++) { // Colonne
            if (value == data[rs][cs]) {
                temp = data[rs][cs];
                break;
            }
        }
    }

    return temp;
}
