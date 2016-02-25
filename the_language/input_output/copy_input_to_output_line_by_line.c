#include <stdio.h>
#include <stdlib.h>

enum { MAX_LINE = 64, };

void copy_line_by_line(FILE *fin, FILE *fout);

int main(void) {
    return(EXIT_SUCCESS);
}

void copy_line_by_line(FILE *fin, FILE *fout) {
    char buf[MAX_LINE];

    while (fgets(buf, MAX_LINE, fin) != NULL)
        fputs(buf, fout);
}
