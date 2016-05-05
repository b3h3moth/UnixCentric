#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <inttypes.h>

enum types {CHAR, UCHAR, SHORT, USHORT, INT, UINT, LONG, ULONG};

union data_tag {
    char valchar;
    short valshort;
    int valint;
    unsigned int valuint;
    long valong;
};

typedef union data_tag Data;

// Function Prototypes
void check_error(int type, char *val, void(*print)(char *, Data *));
void print(char *fmt, Data *d);

int main(int argc, char *argv[]) {
    check_error(4, "10", &print);

    return(EXIT_SUCCESS);
}

// testing, it doesn't work well!
void check_error(int type, char *val, void(*print)(char *, Data *)) {
    Data value;

    if (type == INT) {
        value.valint = atol(val);
        print("%d\n", &value);
    }
}

void print(char *fmt, Data *d) {
    char *format = (void *)fmt;

    printf(format, d->valint);
}
