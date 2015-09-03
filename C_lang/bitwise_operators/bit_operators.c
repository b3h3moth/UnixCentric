#include <stdio.h>
#include <stdlib.h>

void bit_swap(int *x, int *y);

int main(void) {
    unsigned char num_a = 1;    // binario 00000001
    unsigned char num_b = 10;   // binario 00001010
    unsigned char num_c = 100;  // binario 01100100

    // ~
    // One's complement operator (Operatore di completamento a uno)
    // Inverte tutti i bit dell'operando su cui agisce
    unsigned char res_not_a = ~num_a; // binario 11111110
    unsigned char res_not_b = ~num_b; // binario 11110101
    unsigned char res_not_c = ~num_c; // binario 10011011

    // &
    // Bitwise AND (Operatore AND bit per bit)
    // Confronta i bit dei due operandi
    // Il risultato e' 1 (true) se entrambi gli operando valgono 1
    unsigned char res_and_1 = num_a & num_b;
    unsigned char res_and_2 = num_b & num_c;
    unsigned char res_and_3 = num_a & num_c;


    unsigned char or_num = num_b | num_c; 
    unsigned char xor_num = num_b ^ num_c;

    printf("  ~%d = %d - hex.0x%x\n", num_a, res_not_a, res_not_a);
    printf(" ~%d = %d - hex.0x%x\n", num_b, res_not_b, res_not_b);
    printf("~%d = %d - hex.0x%x\n", num_c, res_not_c, res_not_c);

    printf("(AND) %d & %d = %d - hex.0x%x\n", num_b, num_c, res_and_1, res_and_1);
    printf(" (OR) %d | %d = %d - hex.0x%x\n", num_b, num_c, or_num, or_num);
    printf("(XOR) %d ^ %d = %d - hex.0x%x\n", num_b, num_c, xor_num, xor_num);

    return(EXIT_SUCCESS);
}
