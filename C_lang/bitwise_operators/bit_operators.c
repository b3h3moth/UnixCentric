#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned char num_a = 31; // binario 00011111 - esadecimale 0x1F
    unsigned char num_b = 10; // binario 00001010 - esadecimale 0x0A
    unsigned char num_c = 73; // binario 01001001 - esadecimale 0x49

    // ~
    // One's complement operator (Operatore di completamento a uno)
    // Inverte tutti i bit dell'operando su cui agisce
    unsigned char res_not_a = ~num_a;
    unsigned char res_not_b = ~num_b;
    unsigned char res_not_c = ~num_c;

    // &
    // Bitwise AND (Operatore AND bit per bit)
    // Confronta i bit dei due operandi
    // Il risultato e' 1 se entrambi gli operandi valgono 1
    unsigned char res_and_1 = num_a & num_b;
    unsigned char res_and_2 = num_b & num_c;
    unsigned char res_and_3 = num_c & num_a;

    // |
    // Bitwise inclusive OR (Operatore OR bit per bit inclusivo)
    // Confronta i bit dei due operandi
    // Il risultato e' sempre 1 tranne se i due operandi valgono 0
    unsigned char res_or_1 = num_a | num_b; 
    unsigned char res_or_2 = num_b | num_c; 
    unsigned char res_or_3 = num_c | num_a; 

    // ^
    // Bitwise exclusive OR, XOR (Operatore OR bit per bit esclusivo o XOR)
    // Confronta i bit dei due operandi
    // Il risultato e' 1 solo se un operando vale 1 e l'altro vale 0
    unsigned char res_xor_1 = num_a ^ num_b;
    unsigned char res_xor_2 = num_b ^ num_c;
    unsigned char res_xor_3 = num_c ^ num_a;

    printf("One's complement operator ( ~ )\n");
    printf("~%d = %d (hex: 0x%x)\n", num_a, res_not_a, res_not_a);
    printf("~%d = %d (hex: 0x%x)\n", num_b, res_not_b, res_not_b);
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
