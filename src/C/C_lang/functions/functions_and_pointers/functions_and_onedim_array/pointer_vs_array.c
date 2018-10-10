#include <stdio.h>
#include <stdlib.h>

char vec[] = "abcdefghijklmnopqrstuvwxyz";

// Function Prototypes
void arr_func(char ch[10]);
void ptr_func(char *ptr);

/* Lo scopo del programma e' di verificare l'uguaglianza tra puntatori ed array
allorquando il parametro formale di una funzione dovesse essere per l'appunto
un array o un puntatore. In questo caso infatti il parametro formale viene
sempre convertito in un puntataore. */

int main(void) {
    printf("Address of global array: %#x\n\n", &vec);
    arr_func(vec);
    ptr_func(vec);

    return(EXIT_SUCCESS);
}

void arr_func(char ch[10]) {
    printf("Address of array parameter: %#x\n", &ch);
    printf("       Address of &(ch[0]): %#x\n", &(ch[0]));
    printf("       Address of &(ch[1]): %#x\n", &(ch[1]));
    printf("       Address of     ++ch: %#x\n", ++ch);
}

void ptr_func(char *pr) {
    puts(" ");
    printf("Address of pointer paramet: %#x\n", &pr);
    printf("       Address of &(pr[0]): %#x\n", &(pr[0]));
    printf("       Address of &(pr[1]): %#x\n", &(pr[1]));
    printf("       Address of     ++pr: %#x\n", ++pr);
}
