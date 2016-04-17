#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { OFFSET = 3, MAX_BUF = 50 };

int main(void) {
    char string1[MAX_BUF] = "Take a walk on the wild side";
    char string2[MAX_BUF] = "Rastaman vibration positive";
    char buf[MAX_BUF];

    // Testing memset()
    printf("%7s %s\n", "Before:", string1);
    memset(string1 + OFFSET, 'X', 10);
    printf("%7s %s\n", "After:",string1);

    // Testing memcpy()
    strcpy(buf, string2);
    printf("%7s %s\n", "Before:", buf);
    memcpy(buf + 2, buf + 12, 10);
    printf("%7s %s\n", "After:", buf);
    memcpy(buf + 2, buf + 12, 10);
    printf("%7s %s\n", "After:", buf);

    return(EXIT_SUCCESS);
}
