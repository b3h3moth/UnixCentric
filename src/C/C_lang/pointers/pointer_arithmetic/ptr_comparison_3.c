#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { MAXBUF=50 };

void reverse(char *string);

/* Lo scopo del programma e' di invertire una stringa mediante l'aritmetica
dei puntatori, nello specifico comparazione tra puntatori */

int main(void) {
    char buf[MAXBUF];

    printf("Enter the string:\n");
    fgets(buf, MAXBUF, stdin);
    reverse(buf);
    printf("Reversing:\n%s", buf);

    return (EXIT_SUCCESS);
}

void reverse(char *string) {
    char *left_ptr = string;
    char *right_ptr = &string[strlen(string) - 1];
    char tmp;

    while (left_ptr < right_ptr) {
        tmp = *left_ptr;
	    *left_ptr = *right_ptr;
	    *right_ptr = tmp;
	    left_ptr++;
	    right_ptr--;
    }
}
