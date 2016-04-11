#include <stdio.h>
#include <stdlib.h>

enum { ROW = 5, COL = 15 };

int main(void) {
    char str1[] = "C Language";
    char str2[] = "C++ Language";
    char str3[] = "Perl Language";
    char str4[] = "Lisp Language";
    char str5[] = "AWK Language";

    char *ptr1 = str1, *ptr2 = str2, *ptr3 = str3, *ptr4 = str4, *ptr5 = str5;

    // Array di puntatori
    char *arr[5] = {ptr1, ptr2, ptr3, ptr4, ptr5};

    for (int i=0; i<5; i++)
        printf("%s\n", arr[i]);

    return(EXIT_SUCCESS);
}
