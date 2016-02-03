#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>

enum types {CHAR, UCHAR, SHORT, USHORT, INT, UINT, LONG, ULONG};

union data_val {
    char valchar;
    short valshort;
    int valint;
    unsigned int valuint;
    long valong;
};

// Function Prototypes
void check_error(char *type, char *val, void(*print)(char *, union data_val *));
void print(char *fmt, union data_val *d);

int main(void) {
    check_error(5, "0", "int %d\n", &print);
    return(EXIT_SUCCESS);
}

void check_error(char *type, char *val, void(*print)(char *, union data_val *)) {
    union data_val myval;

    if (data_type == INT) {
        myval.valint = atoll(val);
        if (atoll(val) > INT_MAX) {
            fprintf(stderr, "[Error]: Integer Overflow on type 'int'.\n"
                    "Available numeric range: from '%d' to '%d'\n", 
                    INT_MIN, INT_MAX);
        } else if (myval.valint < INT_MIN) {
            fprintf(stderr, "[Error]: Integer Undrflow on type 'int'.\n"
                    "Available numeric range: from '%d' to '%d'\n", 
                    INT_MIN, INT_MAX);
        } else if (myval.valint == 0) 
            printf("000000000000000000\n");
        print(&myval, format);
    } else if (data_type == UINT) {
        myval.valuint = atoll(val);
        printf(format, atoll(val));
        if (myval.valuint > UINT_MAX) {
            fprintf(stderr, "[Error]: Integer Overflow on type 'int'.\n"
                    "Available numeric range: from '%d' to '%u'\n", 
                    0, UINT_MAX);
        } else if (myval.valuint < 0) {
            fprintf(stderr, "[Error]: Integer Undrflow on type 'int'.\n"
                    "Available numeric range: from '%d' to '%u'\n", 
                    0, UINT_MAX);
        }
        print(&myval, format);
    }
}

void print(char *fmt, union data_val *d) {
    char *format = (void *)fmt;

    printf(format, d->valuint);
}
