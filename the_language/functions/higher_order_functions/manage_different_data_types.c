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
void check_error(int type, char *val, void(*print)(char *, union data_val *));
void print(char *fmt, union data_val *d);

int main(void) {
    check_error(4, "4147483648", &print);
    return(EXIT_SUCCESS);
}

// testing, it doesn't work well!
void check_error(int type, char *val, void(*print)(char *, union data_val *)) {
    union data_val value;

    if (type == INT) {
        value.valint = atoll(val);
        
        if (value.valint > INT_MAX)
            fputs("0000000000", stdout);

        print("%d\n", &value);
    }
        
}

void print(char *fmt, union data_val *d) {
    char *format = (void *)fmt;

    printf(format, d->valuint);
}
