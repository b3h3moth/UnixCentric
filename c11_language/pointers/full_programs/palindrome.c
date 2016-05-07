#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AP_SIZE ( sizeof(str) / sizeof(str[0]) )

int main(void) {
    char *first, *last;
    size_t len;

    char str[] = { "abab" };
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
