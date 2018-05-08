#include <stdio.h>
#include <stdlib.h>
#include "kmp.h"

int main(void) {
    char *string = "tale a walk on the wild side";
    char *pattern = "alk";

    printf("%s\n", kmp(pattern, string));
    return(EXIT_SUCCESS);
}
