#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char str[] = "C Language Programming";
    printf("%.*s", strlen(str), str);

    return(EXIT_SUCCESS);
}
