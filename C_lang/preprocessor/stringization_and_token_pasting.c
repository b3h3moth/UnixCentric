#include <stdio.h>
#include <stdlib.h>

#define PRINT_CHAR(c)   printf(#c " = '%c'(%d)\n", c, c)
#define ID_(x)          i##x

/* Le definizioni di macro possono contenere due operatori speciali:
- '#'  converte un argomento in una stringa, da cui 'stringization';
- '##' compatta/incolla assieme due token, da cui 'token pasting';
*/
int main(void) {

    char ID_(1)='a', ID_(2)='b', ID_(3)='c';

    PRINT_CHAR(ID_(1)); // printf("ID_(1)" " = '%c'(%d)\n", i1, i1);
    PRINT_CHAR(ID_(2)); // printf("ID_(2)" " = '%c'(%d)\n", i2, i2);
    PRINT_CHAR(ID_(3)); // printf("ID_(3)" " = '%c'(%d)\n", i3, i3);

    // L'operatore detto token pasting da il meglio con l'utilizzo di funzioni
    return(EXIT_SUCCESS);
}
