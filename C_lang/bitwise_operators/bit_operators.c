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
    // Il risultato e' 1 (true) se entrambi gli operandi sono true (1)
    unsigned char res_and_1 = num_a & num_b;
    unsigned char res_and_2 = num_b & num_c;
    unsigned char res_and_3 = num_c & num_a;

    // |
    // Bitwise inclusive OR (Operatore OR bit per bit inclusivo)
    // Confronta i bit dei due operandi
    // Sempre true (1) tranne se i due operandi sono false (0)
    unsigned char res_or_1 = num_a | num_b; 
    unsigned char res_or_2 = num_b | num_c; 
    unsigned char res_or_3 = num_c | num_a; 

    // ^
    // Bitwise exclusive OR, XOR (Operatore OR bit per bit esclusivo o XOR)
    // Confronta i bit dei due operandi
    // True (1) solo se un operando e' 1 (true) e l'altro e' 0 (false)
    unsigned char res_xor_1 = num_a ^ num_b;
    unsigned char res_xor_2 = num_b ^ num_c;
    unsigned char res_xor_3 = num_c ^ num_a;

    printf("One's complement operator ( ~ )\n");
    printf("  ~%d = %d (hex: 0x%x)\n", num_a, res_not_a, res_not_a);
    printf(" ~%d = %d (hex: 0x%x)\n", num_b, res_not_b, res_not_b);
    printf("~%d = %d (hex: 0x%x)\n", num_c, res_not_c, res_not_c);

    printf("\nBitwise AND ( & )\n");
    printf("%3d & %3d = %3d (hex: 0x%x)\n", num_a, num_b, res_and_1, res_and_1);
    printf("%3d & %3d = %3d (hex: 0x%x)\n", num_b, num_c, res_and_2, res_and_2);
    printf("%3d & %3d = %3d (hex: 0x%x)\n", num_c, num_a, res_and_3, res_and_3);
    
    printf("\nBitwise inclusvie OR ( | )\n");
    printf("%3d | %3d = %3d (hex: 0x%x)\n", num_a, num_b, res_or_1, res_or_1);
    printf("%3d | %3d = %3d (hex: 0x%x)\n", num_b, num_c, res_or_2, res_or_2);
    printf("%3d | %3d = %3d (hex: 0x%x)\n", num_c, num_a, res_or_3, res_or_3);

    printf("\nBitwise exclusvie OR, or XOR ( ^ )\n");
    printf("%3d ^ %3d = %3d (hex: 0x%x)\n", num_a, num_b, res_xor_1, res_xor_1);
    printf("%3d ^ %3d = %3d (hex: 0x%x)\n", num_b, num_c, res_xor_2, res_xor_2);
    printf("%3d ^ %3d = %3d (hex: 0x%x)\n", num_c, num_a, res_xor_3, res_xor_3);

    return(EXIT_SUCCESS);
}
