#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_CHAR(c)   printf(#c " = '%c'(%d)\n", c, c)

/* Le definizioni di macro possono contenere due operatori speciali:
- '#'  converte un argomento in una stringa, da cui 'stringization';
- '##' compatta/incolla assieme due token, da cui 'token pasting';
*/

int main(void) {
    char football_team[] = "Juventus Footbal Club 1897";

    for (int i=0; i<strlen(football_team); i++)
        PRINT_CHAR(football_team[i]);

    return(EXIT_SUCCESS);
}
