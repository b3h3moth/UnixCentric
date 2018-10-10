#include <stdio.h>
#include <stdlib.h>

void squeeze(char str[], int ch);

/* Lo scopo del programma e' di eliminare tutte le occorrenze di uno specifico
carattere da una stringa, modificandola mediante la funzione squeeze() */

int main(void) {
    char my_str[] = "Takxxxex xaxxx xxxwxxaxxxlxxk onxx xthxxe wxilxd sxxidxe!";
    int c = 'x';

    squeeze(my_str, c);
    printf("%s\n", my_str);

    return(EXIT_SUCCESS);
}

/* La funzione squeeze() elimina tutte le occorrenze di 'ch' da 'str' */
void squeeze(char str[], int ch) {
    int i, j;

    for (i = j = 0; str[i] != '\0'; i++)
        if (str[i] != ch)
            str[j++] = str[i];
    str[j] = '\0';
}
