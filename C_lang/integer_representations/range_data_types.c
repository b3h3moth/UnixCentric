#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// It prints the typical range for C integral data types

int main(void) {
    char *data_types[] = { "char", "unsigned char", "signed char", "short", 
                           "unsigned short", "int", "unsigned int", "long", 
                           "unsigned long", "long long", 
                           "unsigned long long" };

    printf("Byte and range for each C data types\n");

    printf("%19s -%2d byte - MIN=%d | MAX=%d\n", 
            data_types[0], sizeof(char), CHAR_MIN, CHAR_MAX);

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

    printf("%19s -%2d byte\n", data_types[6], sizeof(unsigned int));
    printf("%19s -%2d byte\n", data_types[7], sizeof(long));
    printf("%19s -%2d byte\n", data_types[8], sizeof(unsigned long));
    printf("%19s -%2d byte\n", data_types[9], sizeof(long long));
    printf("%19s -%2d byte\n", data_types[10], sizeof(unsigned long long));

    return(EXIT_SUCCESS);
}
