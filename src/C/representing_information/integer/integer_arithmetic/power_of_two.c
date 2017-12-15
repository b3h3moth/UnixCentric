#include <stdio.h>
#include <stdlib.h>

/* The function returns 1 if the argument is a power of two and 0 otherwise */
unsigned char power_of_two(unsigned char n) {
    return (n == 0) ? 0 : (n & (n - 1)) == 0;
}

int main(void) {
    unsigned char arr[] = {8, 16, 24, 13, 32, 65, 254};
    int i;

    for (i = 0; i<sizeof(arr)/sizeof(arr[0]); i++)
        printf("%3d - is a power of two? %d\n", arr[i], power_of_two(arr[i]));

    return(EXIT_SUCCESS);
}
