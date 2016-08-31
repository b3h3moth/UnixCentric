#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE    20

/* Lo scopo del programma e' verificare se una stringa ricevuta in input e'
palindroma o meno. */

int main(int argc, char *argv[]) {
    char *first, *last;
    size_t len;
    char *str = calloc(BUF_SIZE, sizeof(char));

    fputs("entry string: ", stdout);
    scanf("%19s", str);

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
        fputs("The string is Palindrome", stdout);

    return(EXIT_SUCCESS);
}
