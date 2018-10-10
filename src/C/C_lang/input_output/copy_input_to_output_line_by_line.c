#include <stdio.h>
#include <stdlib.h>

enum { MAX_LINE = 64, };

void copy_line_by_line(FILE *fin, FILE *fout);

/* Lo scopo del programma e' di creare una funzione compatta che cosenta una
veloce redirezione dello standard input verso lo standard output; nel caso
specifico il programma, dopo essere stato compilato, puo' essere lanciato in
questo modo:

$ copylinebyline < input_file.txt
*/

int main(void) {

    copy_line_by_line(stdin, stdout);

    return(EXIT_SUCCESS);
}

void copy_line_by_line(FILE *fin, FILE *fout) {
    char buf[MAX_LINE];

    while (fgets(buf, MAX_LINE, fin) != NULL)
        fputs(buf, fout);
}
