#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_strfunc.h"

int main(void) {
    char *src = "Take a walk on the wild side";
    char *dest = malloc(sizeof(src)+1);
    
    my_strncpy(dest, src,  strlen(src)+1);
    
    printf(" src: %s\n", src);
    printf("dest: %s\n", dest);

    return(EXIT_SUCCESS);
}
