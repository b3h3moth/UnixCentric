#include <stdio.h>
#include <stdlib.h>

/* The program's purpose is to test sscanf() function  */

int main(void) {
    const char str[] = "1982/08/12 21:30:37;Unix;Operating;System";
    const char *ptr = str;
    char field[20];

    /* The second string to work with has been taken from /etc/passwd file;
      the field variable is not an array but a pointer to char, previously
      allocated. */
    const char str2[] = "b3h3m0th:x:1000:1000:,,,:/home/b3h3m0th:/usr/bin/zsh";
    const char *ptr2 = str2;
    char *field2 = (char *)malloc(sizeof(15));

    int n, n2, i = 1;

    printf("Full string: %s\n", str);

    while(sscanf(ptr, "%19[^;]%n", field, &n) == 1) {
        printf("%d field = %s (%d byte)\n", i, field, n);
        ptr += n;
        if (*ptr != ';') /* ';' is the field separator */
            break;
        ++ptr, i++;
    }

    i = 1;
    printf("\nFull string: %s\n", str2);
    while(sscanf(ptr2, "%14[^:]%n", field2, &n2) == 1) {
        printf("%d field = %s (%d byte)\n", i, field2, n2);
        ptr2 += n2;
        if (*ptr2 != ':') /* ':' is the field separator */
            break;
        ++ptr2, i++;
    }

    return(EXIT_SUCCESS);
}
