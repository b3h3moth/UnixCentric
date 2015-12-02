#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
struct {
    char one[4];
    int two;
    char three[4];
} data;

/* Lo scopo del programma e' di scrivere i membri della struttura 'data' in un
file, un char da 4 byte, un int da 4 byte e un altro char da 4 byte, per un
totale di 12 byte. Dopo aver lanciato l'eseguibile, sul file risultante dovra'
essere eseguito un hexdump, in modo tale da verificare l'allinemento dei byte.
*/

int main(void) {
    FILE *fp;

    strcpy(data.one, "foo");
    data.two = 0xAABBCCDD;
    strcpy(data.three, "bar");

    if ((fp = fopen("data.txt", "wb"))) {
        fwrite(&data, sizeof(data), 1, fp);
        fclose(fp);
    }

    return(EXIT_SUCCESS);
}
