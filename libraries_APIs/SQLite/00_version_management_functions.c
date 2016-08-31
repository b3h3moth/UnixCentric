#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' la presentazione di alcune funzioni utili per
esrapolare alcuni dati relativi alla libreria SQLite in uso */

int main(void) {
    printf( "SQLite library version: %s\n", sqlite3_libversion());
    printf("  SQLite library number: %d\n", sqlite3_libversion_number());
    printf("SQLite library sourceid: %s\n", sqlite3_sourceid());

    return(EXIT_SUCCESS);
}
