#include <stdio.h>
#include <stdlib.h>

#define ROWS    3
#define COLS    4

// Function Prototypes
int sum_rows(int arr[][COLS], int rows);
int sum_cols(int (*arr)[COLS]);

int main(void) {
    return(EXIT_SUCCESS);
}

int sum_rows(int arr[][COLS], int rows) {
    static int tot = 0;

    for (int r = 0; r<rows; r++) 
        for (int c = 0; c<COLS; c++) 
            tot += arr[r][c];

    return tot;
}

int sum_cols(int (*arr)[COLS]) {
    return 0;
}
