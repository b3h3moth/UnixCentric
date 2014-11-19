#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

const char *host = "localhost";
const char *user = "b3h3m0th";
const char *pass = "stv21cu";
const char *db_name = "sito";

int main(int argc, char *argv[]) {
    int i;

    MYSQL	*connection;
    MYSQL_RES	*results;
    MYSQL_ROW	row;

    connection = mysql_init(NULL);

    if (mysql_real_connect(connection, host, user, pass, db_name, 0, NULL, 0) == NULL) {
	fprintf(stderr, "Err. connection non riuscita!\n");
	exit(EXIT_FAILURE);
    } else
    	printf("Connessione al database: \'%s\' avvenuta con successo\n", db_name);

    /* Output utf8 */
    mysql_query(connection, "SET NAMES 'utf8'");

    const char *sql = "SELECT title from  avjos16_categories ORDER BY `title` ASC;";

    if (mysql_query(connection, sql)) {
    	fprintf(stderr, "%s\n", mysql_error(connection));
    	fprintf(stderr, "%s\n", sql);
	exit(EXIT_FAILURE);
    }

    /* Elaborazione dei results */
    results = mysql_store_result(connection);

    if (results == NULL) {
    	if(mysql_error(connection))
	    fprintf(stderr, "%s\n", mysql_error(connection));
	else
	    fprintf(stderr, "%s\n", "errore sconosciuto\n");
	exit(EXIT_FAILURE);
    }

    printf("%d record trovati\n", (int)mysql_num_rows(results));

    /* Iterazione dei risultati */
    while ((row = mysql_fetch_row(results)) != NULL) {
    	for (i=0; i<mysql_num_fields(results); i++) {
	    if (row[i] == NULL)
	    	printf("[NULL]\t");
	    else
	    	printf("%25s\n", row[i]);
	}
    }

    mysql_free_result(results);
    mysql_close(connection);

    return(EXIT_SUCCESS);
}
