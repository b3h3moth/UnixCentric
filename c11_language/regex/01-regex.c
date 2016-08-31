#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int regex_match(char *pattern, const char *default_string);

/* Lo scopo del programma e' l'individuazione di un pattern all'interno di una
stringa. */

int main(void) {
    char *default_string = "C Language Programming";
    char *pattern = "gra";

    if (regex_match(pattern, default_string) == 0)
		printf ("Pattern \'%s\' found into the string \'%s\'",  \
                pattern, default_string);
	else
		printf ("Pattern \'%s\' not found into the string \'%s\'",  \
                pattern, default_string);

    return(EXIT_SUCCESS);
}

int regex_match(char *pattern, const char *default_string) {
    int status;
    regex_t preg;

    status = regcomp(&preg, pattern, REG_EXTENDED | REG_NOSUB);

	if (status != 0)
        return(EXIT_FAILURE);

	status = regexec(&preg, default_string, (size_t) 0, NULL, 0);

	if (status != 0) {
        regfree (&preg);
        return(EXIT_FAILURE);
    }

    regfree(&preg);

    return status;
}
