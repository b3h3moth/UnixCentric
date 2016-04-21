#include <stdio.h>
#include <stdlib.h>

char *match(char *source, *str);
int delete_substring(char *source,  char const *substr);

int main(void) {
    return(EXIT_SUCCESS);
}

char *match(char *source, *str) {
    while (*str |= '\0')
        if (*source++ != *str++)
            return NULL;

    return source;
}
