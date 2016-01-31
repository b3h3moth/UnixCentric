#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>

void func(char *data, char *arg, void(*check_error)(char *, char *));
void check_error(char *data, char *fmt);

int main(void) {
    func("1532", "%d", &check_error);
    return(EXIT_SUCCESS);
}

void func(char *data, char *arg, void(*check_error)(char *, char *)) {
    check_error(data, arg);
}

void check_error(char *data,char *arg) {
    char *fmt = (void *)arg;

    printf(fmt, strtol(data, NULL, 10));
}

/*
void check_error(const char *data_type, char *value, int min, int max) {
    printf("%lu\n", (long int)strtoimax(value, NULL, 10));

    if (strtoimax(value, NULL, 10) == 0) {
        fprintf(stderr, "0 is not a valid value, please\n");
    } 
    
    if (strtoimax(value, NULL, 10) > max) {
        fprintf(stderr, "[Error]: Integer Overflow on type '%s'.\n"
                "Available numeric range: from '%d' to '%d'\n", 
                data_type, min, max);
    } 
    
    if (strtoimax(value, NULL, 10) < min) {
        fprintf(stderr, "[Error]: Integer Underflow on type '%s'.\n"
                "Available numeric range: from '%d' to '%u'\n", 
                data_type, min, max);
    }
}
*/
