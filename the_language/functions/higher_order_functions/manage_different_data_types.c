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

int main(int argc, char *argv[]) {

    return(EXIT_SUCCESS);
}

// testing, it doesn't work well!
void check_error(int type, char *val, void(*print)(char *, union data_val *)) {
    /*
     if type is (types)
        check if val is > or < to MIN/MAX
              exit/error 
        else
             set up and call print()
     */

}

void print(char *fmt, union data_val *d) {
    char *format = (void *)fmt;

    printf(format, d->valuint);
}
