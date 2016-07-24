#include <stdio.h>
#include <stdlib.h>
#include <sqlite.h>

/* Lo scopo del programma e' di creare un database per l'inserimento di 
immagini */

int main(void) {
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;
    FILE *fp = NULL;
    int flen = 0;
    int size = 0;
    int rc = 0;
    char *err_msg = 0;
    char *sql = NULL;

    if (
    return(EXIT_SUCCESS);
}
