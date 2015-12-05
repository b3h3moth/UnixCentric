#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// It prints the typical range for C integer data types

int main(void) {
    char *data_types[] = { "char", "unsigned char", "signed char",\
                           "short", "unsigned short", "int", "unsigned int", \
                           "long", "unsigned long", "long long",             \
                           "unsigned long long" };

    fputs("It prints the typical range for C integer data types.\n"
          "min/max macro are defined inside <limits.h> header.\n\n", stdout);

    // char
    printf("%22d %-10s | %10s %-22d\n", 
            CHAR_MIN, "CHAR_MIN", "CHAR_MAX", CHAR_MAX);

    // unsigned char
    printf("%22d %-10s | %10s %-22d\n", 
            0, "min", "UCHAR_MAX", UCHAR_MAX);
    
    // signed char
    printf("%22d %-10s | %10s %-22d\n", 
            SCHAR_MIN, "SCHAR_MIN", "SCHAR_MAX", SCHAR_MAX);

    // (signed) short
    printf("%22d %-10s | %10s %-22d\n", 
            SHRT_MIN, "SHRT_MIN", "SHRT_MAX", SHRT_MAX);

    // unsigned short
    printf("%22d %-10s | %10s %-22d\n", 
            0, "min", "USHRT_MAX", USHRT_MAX);

    // (signed) int
    printf("%22d %-10s | %10s %-22d\n", 
            INT_MIN, "INT_MIN", "INT_MAX", INT_MAX);

    // unsigned int
    printf("%22d %-10s | %10s %-22u\n", 
            0, "min", "UINT_MAX", UINT_MAX);

    // (signed) long
    printf("%22ld %-10s | %10s %-22ld\n", 
            LONG_MIN, "LONG_MIN", "LONG_MAX", LONG_MAX);

    // unsigned long
    printf("%22d %-10s | %10s %-22lu\n", 
            0, "min", "ULONG_MAX", ULONG_MAX);
    
    // (signed) long long
    printf("%22lld %-10s | %10s %-22lld\n", 
            LLONG_MIN, "LLONG_MIN", "LLONG_MAX", LLONG_MAX);

    // unsigned long long
    printf("%22d %-10s | %10s %-22llu\n", 
            0, "miN", "ULLONG_MAX", ULLONG_MAX);

    return(EXIT_SUCCESS);
}
