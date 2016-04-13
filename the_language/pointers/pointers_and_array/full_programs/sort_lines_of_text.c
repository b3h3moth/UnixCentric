#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAX_LINE = 1000 };

char *pbuf[MAX_LINE];

char get_line(void);
int compare_strings(const void * str1, const void *str2);

int main(void) {
    for (int n=0; n < MAX_LINE && (pbuf[n] = get_line()) != NULL; ++n)
        ;

    return(EXIT_SUCCESS);
}
