#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

    printf("take a walk on the wild side, by: ");
    write(1, "Lou Reed.\n", 10);

    fputc('\n', stdout);

    printf("Stand up for your rights, by: ");
    fflush(stdout);
    write(1, "Bob Marley.\n", 12);

    return(EXIT_SUCCESS);
}
