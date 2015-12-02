#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 4

struct {
    char str1[MAX_STR];
    int  value;
    char str2[MAX_STR];
} data;

/* Lo scopo del programma e' di scrivere i membri della struttura 'data' in un
file, un vettore char da 4 byte, un int da 4 byte e un altro vettore char da 4
byte, per un totale di 12 byte. Dopo aver lanciato l'eseguibile, sul file 
risultante dovra' essere eseguito un hexdump, in modo tale da verificare 
l'allinemento dei byte.
*/

int main(void) {
    FILE *fp;
    char *filename = "data.txt";

    // Copia la stringa "xxx" nel membro data.str1
    strcpy(data.str1, "xxx");
    // Inizializza il membro data.value con un valore esadecimale
    data.value = 0xAABBCCDD;
    // Copia la stringa "yy" nel membro data.str2
    strcpy(data.str2, "yyy");

    // Scrittura della struttura 'data' nel file
    if ((fp = fopen(filename, "wb"))) {
        fwrite(&data, sizeof(data), 1, fp);
        fclose(fp);
    }

    return(EXIT_SUCCESS);
}
