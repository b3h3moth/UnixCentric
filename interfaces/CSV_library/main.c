#include <stdio.h>
#include <stdlib.h>
#include "csv.h"

int main(int argc, char *argv[]) {
    char *line;

    while ((line = csv_getline(stdin)) != NULL) {
        printf("%s\n", line);
        for (int i=0; i<csv_nfield(); i++)
            printf("field[%2d] = %s\n", i, csv_field(i));
    }
    
    return(EXIT_SUCCESS);
}

/*
Getting input file for testing:

$ tail -4 main.c | head -n 3 > file.csv
$ make
$ ./a.out < file.csv

"CB", 86.25,"11/4/1998",14:39,-1234.89,876.798,+890.0, 789^2.91,
main, +, -, {, }, [], =, ==, ++, --, exit(0);, 
"ROMA", 90.25,"08/3/1987",9:56AM,+1.0876,76.7228,33.9527,20.345,9823761
*/
