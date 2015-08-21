#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *default_string = "Take a walk on the wild side";
    char *ptr = default_string;

    int defstr_size  = 0;
    char *bkp_copy = NULL;

    // Conta il numero dei caratteri della stringa
    while ( *ptr++ != '\0')
        defstr_size++;

    printf("Size of the default string: %d\n", defstr_size);

    return(EXIT_SUCCESS);
}
