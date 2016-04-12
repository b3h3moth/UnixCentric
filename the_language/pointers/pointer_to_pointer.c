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

    char *pkwords[6] = { 
        keywords[0], keywords[1], keywords[2], 
        keywords[3], keywords[4], keywords[5]
    };


    char *ppk[] = {pkwords[0], pkwords[1], pkwords[2], pkwords[3], pkwords[4], pkwords[5] };

    char **ptppk = ppk;

    for (int i=0; i<sizeof(ppk)/sizeof(ppk[0]); i++)
        printf("%s\n", ptppk[i]);

    return(EXIT_SUCCESS);
}
