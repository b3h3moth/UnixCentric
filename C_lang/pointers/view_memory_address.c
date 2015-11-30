#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ADDR_RANGE  10

typedef unsigned char BYTE;

int main(void) {
    unsigned int addr;
    int i, nbyte;
    BYTE *ptr;
    char str_addr[] = "Address of";

    printf("%9s %6s %#x\n", str_addr, "main()", (unsigned int) main);
    printf("%9s %6s %#x\n", str_addr, "addr", (unsigned int) &addr);

    // Immissione di un indirizzo di memoria in formato esadecimale
    printf("\nHexadecimal address: ");
    scanf("%x", &addr);
    
    // Il numero di byte dell'indirizzo da visualizzare
    printf("How many bytes: ");
    scanf("%d", &nbyte);

    printf("\n%10s %29s %10s\n", "Address", "Byte", "Characters");

    ptr = (BYTE *) addr;

    for (; nbyte > 0; nbyte -= 10) {
        printf("%#10x ", (unsigned int) ptr);

        for (i=0; i<ADDR_RANGE && i<nbyte; i++)
            printf("%.2x ", *(ptr +i));

        /* Nel caso di un numero minore di byte da visualizzare saranno
        inseriti gli spazi sino a raggiungere il numero prefissato */
        for(; i<ADDR_RANGE; i++)
            printf("   ");
        fputc(' ', stdout);

        // Stampa dei soli caratteri 'stampabili', altrimenti '.'
        for (i=0; i<10 && i<nbyte; i++) {
            BYTE ch = *(ptr +i);
            if (!isprint(ch))
                ch = '.';
            printf("%c", ch);
        }
        fputc('\n', stdout);
        ptr += 10;
    }

    return(EXIT_SUCCESS);
}
