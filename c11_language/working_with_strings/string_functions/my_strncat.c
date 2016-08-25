#include <string.h>
#include "my_strfunc.h"

void my_strncat(char *dest, const char *src, size_t n) {
    size_t i;
    size_t len_dest = strlen(dest);

    for (i=0; src[i] && (i < n-1) != '\0'; i++)
        dest[len_dest + i] = src[i];
    
    // Add null-terminated character
    dest[len_dest + i] = '\0';
}
