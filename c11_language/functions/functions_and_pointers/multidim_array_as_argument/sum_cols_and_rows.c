#include <stdio.h>
#include <stdlib.h>

#define ROWS    3
#define COLS    4

// Function Prototypes
int sum_all(int (*arr)[COLS]);
void sum_rows(int arr[][COLS]);
void sum_cols(int [][COLS]);

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

    puts("sum each row element");
    sum_rows(mdarr);
    puts("sum each col element");
    sum_cols(mdarr);
    tot = sum_all(mdarr);

    printf("Total rows and cols: %d\n", tot);

    return(EXIT_SUCCESS);
}

void sum_rows(int arr[][COLS]) {
    int tot_rows;

    for (int r=0; r<ROWS; r++) {
        tot_rows = 0;
        for (int c=0; c<COLS; c++)
            tot_rows += arr[r][c];
        printf("%2d row: %2d total\n", r, tot_rows);
    }
}

void sum_cols(int arr[][COLS]) {
    int tot_cols;

    for (int c=0; c<COLS; c++) {
        tot_cols = 0;
        for(int r=0; r<ROWS; r++)
            tot_cols += arr[r][c];
        printf("%2d col: %2d total\n", c, tot_cols);
    }
}

int sum_all(int arr[][COLS]) {
    static int tot = 0;

    for (int r = 0; r<ROWS; r++) 
        for (int c = 0; c<COLS; c++) 
            tot += arr[r][c];

    return tot;
}
