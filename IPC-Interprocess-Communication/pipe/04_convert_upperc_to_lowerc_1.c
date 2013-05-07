#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    int c;

    while((c = getchar()) != EOF) {
        
        if (isupper(c))
            c = tolower(c);
        
        if (putchar(c) == EOF) {
            fprintf(stderr, "Err: %d putchar() - %s\n", errno, strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (c == '\n')
            fflush(stdout);

        if (c == 'q')
            break;
    }

    return(EXIT_SUCCESS);
}
