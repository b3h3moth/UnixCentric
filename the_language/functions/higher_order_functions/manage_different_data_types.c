#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>

enum types {CHAR, UCHAR, SHORT, USHORT, INT, UINT, LONG, ULONG};

union data_val {
    char valchar;
    short valshort;
    int valint;
    long valong;
};

void check_error(int data_type, char *val, char *format, void(*print)(union data_val *, char *));
void print(union data_val *d, char *fmt);

int main(void) {
    check_error(4, "1532", " int %d\n", &print);
    check_error(5, "-1532", "uint %u\n", &print);
    return(EXIT_SUCCESS);
}

void check_error(int data_type, char *val, char *format, void(*print)(union data_val *, char *)) {
    union data_val myval;
    myval.valint = atol(val);

    if (data_type == INT) {
        print(&myval, format);
    } else if (data_type == UINT) {
        print(&myval, format);
    }
}

void print(union data_val *d, char *fmt) {
    char *format = (void *)fmt;

    printf(format, d->valint);
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
