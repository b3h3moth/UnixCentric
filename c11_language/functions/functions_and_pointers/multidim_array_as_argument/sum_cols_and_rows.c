#include <stdio.h>
#include <stdlib.h>

#define ROWS    3
#define COLS    4

// Function Prototypes
int sum_all(int (*arr)[COLS], int rows);
int sum_rows(int arr[][COLS], int rows);
int sum_cols(int [][COLS], int rows);

/* Lo scopo del programma e' di provare le invocazioni di una funzione il cui
parametro formale e' un array multidimensionale e individuare quindi le varie
signatures possibili. */

int main(void) {
    int tot;
    int mdarr[ROWS][COLS] = { 
        {1,3,5,7},
        {2,4,6,8},
        {0,1,2,3}
    };

    tot = sum_all(mdarr, ROWS);
    printf("Total rows: %d\n", tot);

    return(EXIT_SUCCESS);
}

int sum_all(int arr[][COLS], int rows) {
    static int tot = 0;

    for (int r = 0; r<rows; r++) 
        for (int c = 0; c<COLS; c++) 
            tot += arr[r][c];

    return tot;
}

int sum_cols(int (*arr)[COLS]) {
    return 0;
}
