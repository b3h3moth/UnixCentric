#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utils.h"

int main(void) {
    char list_of_char[] = {'a','b','c'};
    int list_of_int[] = {123456, 234567, 891234};

    printf("Characters: \n");
    for (int i=0; i<3; i++) {
        print_bit((unsigned char *)&list_of_char[i], sizeof(char));
        print_byte((unsigned char *)&list_of_char[i], sizeof(char));
    }

    printf("Integers:\n");
    for (int i=0; i<3; i++) {
        print_bit((unsigned char *)&list_of_int[i], sizeof(int));
        print_byte((unsigned char *)&list_of_int[i], sizeof(int));
    }

    return(EXIT_SUCCESS);
}
