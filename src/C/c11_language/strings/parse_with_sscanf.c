#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char str[] = "1975/03/03 06:00:00;info1;info2;info3";
    const char *ptr = str;
    char field[20];
    int n;

    while(sscanf(ptr, "%31[^;]%n", field, &n) == 1) {
        printf("Filed = %s\n", field);
        ptr += n;
        if (*ptr != ';')
            break;
        ++ptr;
    }

    return(EXIT_SUCCESS);
}
