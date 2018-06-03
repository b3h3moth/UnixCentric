#include <stdio.h>
#include <stdlib.h>

/* The program's purpose is to test sscanf() function  */

int main(void) {
    const char str[] = "1982/08/12 21:30:37;Unix;Operating;System";
    const char *ptr = str;
    char field[20];
    int n, i = 1;

    while(sscanf(ptr, "%19[^;]%n", field, &n) == 1) {
        printf("%d field = %s (%d byte)\n", i, field, n);
        ptr += n;
        if (*ptr != ';') /* ';' is the field separator */
            break;
        ++ptr, i++;
    }

    return(EXIT_SUCCESS);
}
