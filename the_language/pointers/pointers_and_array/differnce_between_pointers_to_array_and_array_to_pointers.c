#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char stra[] = "C Language";
    char strb[] = "C++ Language";
    char strc[] = "Perl Language";
    char strd[] = "Lisp Language";
    char stre[] = "AWK Language";

    char *ptr1 = stra, *ptr2 = strb, *ptr3 = strc, *ptr4 = strd, *ptr5 = stre;

    // Array di puntatori
    char *arr[5] = {ptr1, ptr2, ptr3, ptr4, ptr5};

    for (int i=0; i<5; i++)
        printf("%s\n", arr[i]);

    return(EXIT_SUCCESS);
}
