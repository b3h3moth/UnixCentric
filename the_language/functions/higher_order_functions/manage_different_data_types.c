#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>
#include <string.h>

void check_error(char *data, char *arg, char *format, long min, long max, void(*verify)(char *, char *, char *, int, int));
void verify(char *data, char *arg, char *format);

int main(void) {

    return(EXIT_SUCCESS);
}

void check_error(char *data, char *arg, char *format, long min, long max, void(*verify)(char *, char *, char *, int, int)) {
        verify(data, arg, format, min, max);
}

void verify(char *data, char *arg, char *format) {
    char *fmt = (void *)format;
    
    if ((atoll(value)) > max) {
        fprintf(stderr, "[Error]: Integer Overflow on type '%s'.\n"
                "Available numeric range: from '%d' to '%d'\n", 
                data_type, min, max);
        exit(EXIT_FAILURE);
    } else if ((atoll(value)) < min) {
        fprintf(stderr, "[Error]: Integer Underflow on type '%s'.\n"
                "Available numeric range: from '%d' to '%d'\n", 
                data_type, min, max);
        exit(EXIT_FAILURE);
    }
}

