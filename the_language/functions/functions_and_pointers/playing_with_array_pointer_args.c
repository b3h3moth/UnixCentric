#include <stdio.h>
#include <stdlib.h>

char vec[] = "abcdefghijklmnopqrstuvwxyz";

// Function Prototypes
void arr_func(char ch[10]);
void ptr_func(char *ptr);

int main(void) {
    arr_func(vec);
    ptr_func(vec);

    return(EXIT_SUCCESS);
}

void arr_func(char ch[10]) {
    printf("     &ch: %#x\n", &ch);
    printf("&(ch[0]): %#x\n", &(ch[0]));
    printf("&(ch[1]): %#x\n", &(ch[1]));
    printf("    ++ch: %#x\n", ++ch);
}

void ptr_func(char *pr) {
    printf("     &pr: %#x\n", &pr);
    printf("&(pr[0]): %#x\n", &(pr[0]));
    printf("&(pr[1]): %#x\n", &(pr[1]));
    printf("    ++pr: %#x\n", ++pr);
}
