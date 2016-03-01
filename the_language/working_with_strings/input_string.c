#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char ch, line[100];
    unsigned i = 0;
    
    printf("Type a string: ");
    while ((ch = getchar()) != '\n') {
        if (i < 99)
            line[i++] = ch;
        else {
            printf("Sorry, the string is too large.\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("%s\n", line);

    return(EXIT_SUCCESS);
}
