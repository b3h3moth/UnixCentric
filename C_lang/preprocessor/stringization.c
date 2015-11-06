#include <stdio.h>
#include <stdlib.h>

#define PRINT_CHAR(c)   printf(#c " = '%c'(%d)\n", c, c)

/* Le definizioni di macro possono contenere due operatori speciali:
- '#'  converte un argomento in una stringa, da cui 'stringization';
- '##' compatta insieme due token 
*/
int main(void) {
    char ch = 'z';

    PRINT_CHAR(ch); // Output: ch = 'z'(122)

    return(EXIT_SUCCESS);
}
