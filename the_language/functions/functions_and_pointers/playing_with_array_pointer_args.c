#include <stdio.h>
#include <stdlib.h>

char vec[] = "abcdefghijklmnopqrstuvwxyz";

// Function Prototypes
void arr_func(char ch[10]);

int main(void) {
    arr_func(vec);

    return(EXIT_SUCCESS);
}

void arr_func(char ch[10]) {
    printf("     &ch: %#x\n", &ch);
    printf("&(ch[0]): %#x\n", &(ch[0]));
    printf("&(ch[1]): %#x\n", &(ch[1]));
}
