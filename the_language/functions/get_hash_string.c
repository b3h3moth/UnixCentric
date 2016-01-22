#include <stdio.h>
#include <stdlib.h>

unsigned int hash(char *str);

int main(void) {
    unsigned int val;
    char *string = "secrets";
    val = hash(string);
    printf("hash of %s is: %d\n", string, val);

    return(EXIT_SUCCESS);
}

unsigned int hash(char *str) {
    unsigned char *p;
    int h;

    for (p = (unsigned char *)str; *p != '\0'; p++)
        h = 31 * h + *p;

    return h % 4093;
}

