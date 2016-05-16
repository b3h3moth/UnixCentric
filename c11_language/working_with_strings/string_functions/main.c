#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string_function.h"

int main(void) {
    char *src = "popolo";
    char *dest = malloc(sizeof(src)+1);
    
    my_strncpy(dest, src,  strlen(src)+1);
    
    printf(" src: %s\n", src);
    printf("dest: %s\n", dest);

    return(EXIT_SUCCESS);
}
