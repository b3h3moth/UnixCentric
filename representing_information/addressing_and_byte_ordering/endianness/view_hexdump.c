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

00000000  61 62 63 00 12 ab cd ef 78 79 7a 00              |abc.....xyz.|
0000000c

- byte-ordering Big-endian;
- il valore del MSB (most significant byte) e' 0x61;
- il MSB sta sull'indirizzo piu' basso;
- gli altri byte decrescono in ordine di importanza;
- la lettura in esadecimale va da sinistra a destra;
- il valore del LSB (least significant byte) e' 0x00;
- il LSB sta sull'indirizzo piu' alto;

Su un x86-32 Little-Endian 32bit il risultato di un hexdump sarebbe:

00000000  61 62 63 00 ef cd ab 12  78 79 7a 00              |abc.....xyz.|
0000000c

- byte-ordering Little-endian;
- il valore del LSB (least significant byte) e' 0x61;
- il LSB sta sull'indirizzo piu' basso;
- gli altri byte aumentano in ordine di importanza;
- la lettura in esadecimale va da destra a sinistra;
- il valore del MSB (most significant byte) e' 0x00;
- il MSB sta sull'indirizzo piu' alto;
*/
