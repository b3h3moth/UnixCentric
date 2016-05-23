#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main(void) {
    printf("SQLite library version: %s\n", sqlite3_libversion());
    printf("SQLite library number: %d\n", sqlite3_libversion_number());

    return(EXIT_SUCCESS);
}
