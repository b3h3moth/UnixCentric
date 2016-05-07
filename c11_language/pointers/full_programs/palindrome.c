#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *first, *last;
    size_t len;
    char *str;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    len = strlen(str);

    first = str;
    last = &str[len-1];
    
    while (first < last) {
        if (*first != *last)
            break;
        first++;
        last--;
    }

    if (first >= last)
        puts("palindrome");

    return(EXIT_SUCCESS);
}
