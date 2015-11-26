#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int num1 = 0x20;   // 32 decimale
    unsigned int num2 = 0x30;   
    unsigned int num3 = 32;     // 0x20 hex

    /* XOR ^ corrisponde a "diverso" (Not Equals), mentre !^ XNOR (NOT XOR)
    corrisponde a "uguale" (Equals). Si ottiene questo risultato perche' 
    una XOR su due valori uguali ritorna una sequenza di zero, ovvero false, 
    per cui utilizzando XNOR si otterra' la corretta simulazione. */
    
    if (!(num1 ^ num2))
        printf("%#x and %#x are equals\n", num1, num2);
    else
        printf("%#x and %#x are not equals\n", num1, num2);

    if (!(num2 ^ num3))
        printf("%#x and %#x are equals\n", num2, num3);
    else
        printf("%#x and %#x are not equals\n", num2, num3);

    if (!(num1 ^ num3))
        printf("%#x and %#x are equals\n", num1, num3);
    else
        printf("%#x and %#x are not equals\n", num1, num3);
    
    return(EXIT_SUCCESS);
}
