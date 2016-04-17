#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAX_BUF = 50 };

int main(void) {
    char string1[MAX_BUF] = "Take a walk on the wild side";
    char string2[MAX_BUF] = "Rastaman vibration positive";
    char buf[MAX_BUF];

    printf("%7s %s\n", "Before:", string1);
    memset(string1 + 5, 'X', 10);
    printf("%7s %s\n", "After:",string1);

    strcpy(buf, string2);
    printf("%7s %s\n", "Before:", buf);
    memset(string1 + 5, 'X', 10);
    memcpy(buf + 4, buf + 16, 10);
    printf("%7s %s\n", "After:", buf);
    memset(string1 + 5, 'X', 10);
    memcpy(buf + 4, buf + 16, 10);
    printf("%7s %s\n", "After:", buf);

    return(EXIT_SUCCESS);
}
