#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 4

struct {
    char str1[MAX_STR];
    int  value;
    char str2[MAX_STR];
} data;

/* Lo scopo del programma e' di scrivere i valori dei membri della struttura 
'data' all'interno di un file, che sono:
- un vettore char da 4 byte;
- un int da 4 byte;
- un altro vettore char da 4 byte
per un totale di 12 byte. D

Dpo aver lanciato l'eseguibile, sul file risultante dovra' essere eseguito un
hexdump, in modo tale da verificare l'allinemento dei byte, l'output infatti
sara' differente a seconda che si utilizzi una macchina Big-endian oppure una
Little-endian. */

int main(void) {
    FILE *fp;
    char *filename = "data.txt";
    unsigned int data_size = sizeof(data);

    // Copia la stringa "xxx" nel membro data.str1
    strcpy(data.str1, "abc");
    // Inizializza il membro data.value con un valore esadecimale
    data.value = 0x12ABCDEF;
    // Copia la stringa "yy" nel membro data.str2
    strcpy(data.str2, "xyz");

    // Scrittura della struttura 'data' nel file
    if ((fp = fopen(filename, "wb"))) {
        fwrite(&data, sizeof(data), 1, fp);
        fclose(fp);
    }

    printf("struct 'data'(%d byte) written into: '%s'\n", data_size, filename);
    fputs("please check byte ordering incoving an hexdump\n", stdout);
    printf("'hexdump %s' or 'hd %s'\n", filename, filename);

    return(EXIT_SUCCESS);
}

/* Su un PPC Big-Endian 32bit il risultato di un hexdump sarebbe:

$ hd data.txt
00000000  61 62 63 00 12 ab cd ef  78 79 7a 00              |xxx.....yyy.|
0000000c

Seppur molto breve, l'hexdump del file data.txt fornisce diverse informazioni,
anzitutto che si sta utilizzando una macchina con un byte-ordering Big-endian,
poiche' ciascun byte e' scritto da sinistra a destra, ovvero il MSB (Most
Significant Byte) corrisponde al 61 (a), mentre LSB (Least Significant Byte)
corrispinde al byte 7a (z).
*/
