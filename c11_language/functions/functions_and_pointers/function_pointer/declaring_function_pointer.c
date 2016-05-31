#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t process_string(char *str);

int main(void) {
    size_t (*fplen)(char *);
    char *str = "The Art of Programming in C";
    fplen = process_string;
    printf("The length of \"%s\" is: %d\n", str, fplen(str));
    
    return(EXIT_SUCCESS);
}

size_t process_string(char *str) {
    size_t i=0;

    while (*str++)
        i++;

    return i;
}
