#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAX_LINE = 1000 };

char *pline[MAX_LINE];

char *get_line(void);
int compare_strings(const void *str1, const void *str2);

int main(void) {
    int n = 0;

    for ( ; n < MAX_LINE && (pline[n] = get_line()) != NULL; ++n)
        ;

    return(EXIT_SUCCESS);
}

char *get_line(void) {
    char buf[MAX_LINE];
    *pline = NULL;

    if (fgets(buf, MAX_LINE, stdin) != NULL) {
        size_t len = strlen(buf);

        if (buf[len-1] == '\n')
            buf[len-1] = '\0';
        else
            ++len;

        if ((pline = malloc(len)) != NULL)
            strcpy(pline, buf);
    }
    return pline;
}

int compare_strings(const void *str1, const void *str2) {
    return strcmp(*(char **)str1, *(char **)str2);
}
