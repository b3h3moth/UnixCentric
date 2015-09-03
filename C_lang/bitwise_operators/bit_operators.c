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
    // Il risultato e' 1 (true) se entrambi gli operando sono true (1)
    unsigned char res_and_1 = num_a & num_b;
    unsigned char res_and_2 = num_b & num_c;
    unsigned char res_and_3 = num_a & num_c;

    // |
    // Bitwise inclusive OR (Operatore OR bit per bit inclusivo
    // Confronta i bit dei due operandi
    // Sempre true (1) tranne se i due operandi sono false (0)
    unsigned char or_num = num_b | num_c; 
    unsigned char xor_num = num_b ^ num_c;

    printf("One's complement operator ( ~ )\n");
    printf("  ~%d = %d (hex: 0x%x)\n", num_a, res_not_a, res_not_a);
    printf(" ~%d = %d (hex: 0x%x)\n", num_b, res_not_b, res_not_b);
    printf("~%d = %d (hex: 0x%x)\n", num_c, res_not_c, res_not_c);

    printf("\nBitwise AND ( & )\n");
    printf(" %d & %3d = %d (hex: 0x%x)\n", num_a, num_b, res_and_1, res_and_1);
    printf("%d & %3d = %d (hex: 0x%x)\n", num_b, num_c, res_and_2, res_and_2);
    printf(" %d & %3d = %d (hex: 0x%x)\n", num_a, num_c, res_and_3, res_and_3);
    
    printf("\nBitwise AND ( & )\n");
    printf("%d | %d = %d - hex.0x%x\n", num_b, num_c, or_num, or_num);

    printf("(XOR) %d ^ %d = %d - hex.0x%x\n", num_b, num_c, xor_num, xor_num);

    return(EXIT_SUCCESS);
}
