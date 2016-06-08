#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

/* Lo scopo del programma e' di individuare il tipo di dato all'interno dei
record di un database, mediante la classe di memorizzazione (Storage Class). */

int main(void) {
    sqlite3         *db = NULL;
    sqlite3_stmt    *stmt = NULL;
    int             res = 0;
    char            *sql_str = "SELECT msg FROM note order by time;
    int             flags SQLITE_OPEN_READONLY;

    return(EXIT_SUCCESS);
}
