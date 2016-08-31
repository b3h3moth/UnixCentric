#include <stdio.h>
#include <stdlib.h>

#define v(a,b,c)    a ## b ## c

int main(void) {
    int numbers[] = { v(1,2,3), v(4,5,6), v(7,8,), v(9,,), v(,,10), v(,,) };

    for (int i=0; i<sizeof(numbers)/sizeof(numbers[0]); i++)
        printf("%3d\n", numbers[i]);

    char ch1 = 'c';
    char ch2 = 'i';
    char ch3 = 'a';
    char ch4 = 'o';
    char ch5 = '\0';
    
    char string[] = { v(ch1,,), v(,ch2,), v(,,ch3), v(ch4,,), v(ch5,,) };

    printf("%s\n", string);

    return(EXIT_SUCCESS);
}
