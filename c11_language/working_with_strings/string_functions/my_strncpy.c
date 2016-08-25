#include "my_strfunc.h"

void my_strncpy(char *dest, const char *src, size_t n) {
    size_t i;

    for (i=0; i<n && src[i] && (i < n -1); i++) {
        dest[i] = src[i];
    }
    
    dest[i] = '\0';
}
