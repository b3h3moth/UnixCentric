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
    printf("%19s (%d byte:%2d bit) %10s:%-22d %10s:%-22d\n", 
            data_types[0], sizeof(char), 
            CHAR_BIT, "CHAR_MIN", CHAR_MIN, "CHAR_MAX", CHAR_MAX);

    // unsigned char
    printf("%19s (%d byte:%2d bit) %10s:%-22d %10s:%-22d\n", 
            data_types[1], sizeof(unsigned char), 
            CHAR_BIT, "", 0, "UCHAR_MAX", UCHAR_MAX);
    
    // signed char
    printf("%19s (%d byte:%2d bit) %10s:%-22d %10s:%-22d\n", 
            data_types[2], sizeof(signed char), 
            CHAR_BIT, "SCHAR_MIN", SCHAR_MIN, "SCHAR_MAX", SCHAR_MAX);

    // (signed) short
    printf("%19s (%d byte:%2d bit) %10s:%-22d %10s:%-22d\n", 
            data_types[3], sizeof(short), 
            CHAR_BIT*2, "SHRT_MIN", SHRT_MIN, "SHRT_MAX", SHRT_MAX);

    // unsigned short
    printf("%19s (%d byte:%2d bit) %10s:%-22d %10s:%-22d\n", 
            data_types[4], sizeof(unsigned short), 
            CHAR_BIT*2, "", 0, "USHRT_MAX", USHRT_MAX);

    // (signed) int
    printf("%19s (%d byte:%2d bit) %10s:%-22d %10s:%-22d\n", 
            data_types[5], sizeof(int), 
            CHAR_BIT*4, "INT_MIN", INT_MIN, "INT_MAX", INT_MAX);

    // unsigned int
    printf("%19s (%d byte:%2d bit) %10s:%-22d %10s:%11ud\n", 
            data_types[6], sizeof(unsigned int), 
            CHAR_BIT*4, "", 0, "UINT_MAX", UINT_MAX);

    // (signed) long
    printf("%19s (%d byte:%2d bit) %10s:%-22ld %10s:%11ld\n", 
            data_types[7], sizeof(long), 
            CHAR_BIT*8, "LONG_MIN", LONG_MIN, "LONG_MAX", LONG_MAX);

    // unsigned long
    printf("%19s (%d byte:%2d bit) %10s:%-22d %10s:%11lu\n\n", 
            data_types[8], sizeof(unsigned long), 
            CHAR_BIT*8, "", 0, "ULONG_MAX", ULONG_MAX);
    
    // (signed) long long
    printf("%19s (%d byte:%2d bit) %10s:%-22lld %10s:%11lld\n", 
            data_types[9], sizeof(long long), 
            CHAR_BIT*8, "LLONG_MIN", LLONG_MIN, "LLONG_MAX", LLONG_MAX);

    // unsigned long
    printf("%19s (%d byte:%2d bit) %10s:%-22d %10s:%11llu\n\n", 
            data_types[10], sizeof(unsigned long long), 
            CHAR_BIT*8, "", 0, "ULLONG_MAX", ULLONG_MAX);

    return(EXIT_SUCCESS);
}
