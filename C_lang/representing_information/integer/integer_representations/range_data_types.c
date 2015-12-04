#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// It prints the typical range for C integer data types

int main(void) {
    char *data_types[] = { "(unsigned) char", "unsigned char", "signed char",\
                           "short", "unsigned short", "int", "unsigned int", \
                           "long", "unsigned long", "long long",             \
                           "unsigned long long" };

    fputs("It prints the typical range for C integer data types.\n"
          "min/max macro are defined inside <limits.h> header.\n\n", stdout);

    printf("%19s (%d byte:%d bit) CHAR_MIN:'%d' CHAR_MAX:'%d'\n", 
            data_types[0], sizeof(char), CHAR_BIT, CHAR_MIN, CHAR_MAX);

    printf("%19s -%2d byte - MIN=0 | MAX=%d\n", 
            data_types[1], sizeof(unsigned char), UCHAR_MAX);
    
    printf("%19s -%2d byte - MIN=%d | MAX=%d\n", 
            data_types[2], sizeof(signed char), SCHAR_MIN, SCHAR_MAX);

    printf("%19s -%2d byte - MIN=%d | MAX=%d\n", 
            data_types[3], sizeof(short), SHRT_MIN, SHRT_MAX);

    printf("%19s -%2d byte - MIN=0 | MAX=%d\n", 
            data_types[4], sizeof(unsigned short), USHRT_MAX);

    printf("%19s -%2d byte - MIN=%d | MAX=%d\n", 
            data_types[5], sizeof(int), INT_MIN, INT_MAX);

    printf("%19s -%2d byte - MIN=0 | MAX=%ud\n", 
            data_types[6], sizeof(unsigned int), UINT_MAX);

    printf("%19s -%2d byte - MIN=%ld | MAX=%ld\n", 
            data_types[7], sizeof(long), LONG_MIN, LONG_MAX);

    printf("%19s -%2d byte - MIN=0 | MAX=%lu\n", 
            data_types[8], sizeof(unsigned long), ULONG_MAX);
    
    printf("%19s -%2d byte - MIN=%lld | MAX=%lld\n", 
            data_types[9], sizeof(long long), LLONG_MIN, LLONG_MAX);

    printf("%19s -%2d byte - MIN=0| MAX=%llu\n", 
            data_types[10], sizeof(unsigned long long), ULLONG_MAX);

    return(EXIT_SUCCESS);
}
