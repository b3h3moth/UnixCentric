#include <string.h>
#include "my_strfunc.h"

char *my_strncat(char *dest, const char *src, size_t n) {
    size_t i;
    size_t len_dest = strlen(dest);

    for (i=0; i<n && src[i] != '\0'; i++)
        dest[len_dest + i] = src[i];
    
    // Add null-terminated character
    dest[len_dest + i] = '\0';

    return dest;
}
