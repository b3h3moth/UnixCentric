#include <stdio.h>
#include <stdlib.h>

// It prints the typical range for C integral data types

int main(void) {
    char *data_types[] = { "char", "unsigned char", "short", "unsigned shirt",
                           "int", "unsigned int", "long", "unsigned long",
                           "long long", "unsigned long long" };

    printf("Range for C data types\n");
    printf("%19s -%2d byte\n", data_types[0], sizeof(char));
    printf("%19s -%2d byte\n", data_types[1], sizeof(unsigned char));
    printf("%19s -%2d byte\n", data_types[2], sizeof(short));
    printf("%19s -%2d byte\n", data_types[3], sizeof(unsigned short));
    printf("%19s -%2d byte\n", data_types[4], sizeof(int));
    printf("%19s -%2d byte\n", data_types[5], sizeof(unsigned int));
    printf("%19s -%2d byte\n", data_types[6], sizeof(long));
    printf("%19s -%2d byte\n", data_types[7], sizeof(unsigned long));
    printf("%19s -%2d byte\n", data_types[8], sizeof(long long));
    printf("%19s -%2d byte\n", data_types[9], sizeof(unsigned long long));

    return(EXIT_SUCCESS);
}
