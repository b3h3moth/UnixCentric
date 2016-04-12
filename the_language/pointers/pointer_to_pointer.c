#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *keywords[] = { 
        "auto",
        "extern",
        "register",
        "static",
        "void",
        "extern",
    };

    char *str1 = keywords[0];
    char *str2 = keywords[1];
    char *str3 = keywords[2];
    char *str4 = keywords[3];
    char *str5 = keywords[4];
    char *str6 = keywords[5];

    char *ptr[] = {str1, str2, str3, str4, str5, str6 };
    char **ptp = &ptr[0];

    for (int i=0; i<sizeof(ptr)/sizeof(ptr[0]); i++)
        printf("%s\n", ptp[i]);

    return(EXIT_SUCCESS);
}
