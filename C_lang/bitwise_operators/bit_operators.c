#include <stdio.h>
#include <stdlib.h>

#define BIT_1   1
#define BIT_2   2
#define BIT_3   3

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

    // <<
    // Left shift operator (Operatore di scorrimento a sinistra)
    // Permette di spostare i bit dell'operando di sinistra di tanti bit quanti
    // sono indicati dall'operando di destra
    unsigned char res_lf_1 = num_a << BIT_1; // 00011111 << 1 = 00111110
    unsigned char res_lf_2 = num_b << BIT_2; // 00001010 << 2 = 00101000
    unsigned char res_lf_3 = num_c << BIT_3; // 01001001 << 3 = 01001000
    // Il dato utilizzato per tutti gli esempi e' un 'unsigned char' da 1 byte,
    // 8 bit, se lo shift precendente fosse stato eseguito su un 'unsigned int'
    // da 4 byte, 32 bit, il risultato sarebbe stato molto differente, ovvero:
    // 00000000000000000000000001001001 << 3 = 00000000000000000000001001001000
    unsigned int  res_lf_4 = num_c << BIT_3; 

    // >>
    // Right shift operator (Operatore di scorrimento a destra)
    // Permette di spostare i bit dell'operando di sinistra di tanti bit quanti 
    // sono indicati dall'operando di destra
    unsigned char res_rt_1 = num_a >> BIT_1; // 00011111 >> 1 = 00001111
    unsigned char res_rt_2 = num_b >> BIT_2; // 00001010 >> 2 = 00000010
    unsigned char res_rt_3 = num_c >> BIT_3; // 01001001 >> 3 = 00001001

    printf("I'm working on unsigned char (1 byte: 8 bit)\n\n");

    printf("One's complement operator ( ~ )\n");
    printf(" ~%d = %3d (hex: 0x%x)\n", num_a, res_not_a, res_not_a);
    printf(" ~%d = %3d (hex: 0x%x)\n", num_b, res_not_b, res_not_b);
    printf(" ~%d = %3d (hex: 0x%x)\n", num_c, res_not_c, res_not_c);

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

    printf("\nLeft shift operator ( << )\n");
    printf("%3d <<%3d = %3d (hex: 0x%x)\n", num_a, BIT_1, res_lf_1, res_lf_1);
    printf("%3d <<%3d = %3d (hex: 0x%x)\n", num_b, BIT_2, res_lf_2, res_lf_2);
    printf("%3d <<%3d = %3d (hex: 0x%x)\n", num_c, BIT_3, res_lf_3, res_lf_3);
    printf("%3d <<%3d = %3d (hex: 0x%x) - unsigned int (4 byte: 32 bit)\n", \
            num_c, BIT_3, res_lf_4, res_lf_4);

    printf("\nRight shift operator ( >> )\n");
    printf("%3d <<%3d = %3d (hex: 0x%x)\n", num_a, BIT_1, res_rt_1, res_rt_1);
    printf("%3d <<%3d = %3d (hex: 0x%x)\n", num_b, BIT_2, res_rt_2, res_rt_2);
    printf("%3d <<%3d = %3d (hex: 0x%x)\n", num_c, BIT_3, res_rt_3, res_rt_3);

    return(EXIT_SUCCESS);
}
