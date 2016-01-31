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
    check_error(4, "22478345693", " int %d\n", &print);
    check_error(5, "-1532", "uint %d\n", &print);
    return(EXIT_SUCCESS);
}

void check_error(int data_type, char *val, char *format, void(*print)(union data_val *, char *)) {
    union data_val myval;
    myval.valint = atol(val);

    if (data_type == INT) {
        if (myval.valint > INT_MAX) {
            fprintf(stderr, "[Error]: Integer Overflow on type 'int'.\n"
                    "Available numeric range: from '%d' to '%d'\n", 
                    INT_MIN, INT_MAX);
        }
        print(&myval, format);
    } else if (data_type == UINT) {
        print(&myval, format);
    }
}

void print(union data_val *d, char *fmt) {
    char *format = (void *)fmt;

    printf(format, d->valint);
}
