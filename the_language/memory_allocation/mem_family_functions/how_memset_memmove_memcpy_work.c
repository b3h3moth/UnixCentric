#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAX_BUF = 50 };

int main(void) {
    char string1[MAX_BUF] = "Take a walk on the wild side";
    char string2[MAX_BUF] = "qwertyuiopasdfghjklzxcvbnm";
    char buf[MAX_BUF];

    puts("before memset()");
    printf("\t%s\n", string1);
    memset(string1 + 5, 'X', 10);
    puts("\nafter memset()");
    printf("\t%s\n", string1);

    return(EXIT_SUCCESS);
}
