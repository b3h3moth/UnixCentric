#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(int argc, char *arg[]) {
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <db> <SQL statement>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
