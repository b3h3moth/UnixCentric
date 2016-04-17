#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAX_BUF = 50 };

int main(void) {
    char string1[MAX_BUF] = "Take a walk on the wild side";
    char string2[MAX_BUF] = "qwertyuiopasdfghjklzxcvbnm";
    char buf[MAX_BUF];

    printf("%7s %s\n", "Before:", string1);
    memset(string1 + 5, 'X', 10);
    printf("%7s %s\n", "After:",string1);

    return(EXIT_SUCCESS);
}
