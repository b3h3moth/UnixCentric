#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lo scopo del programma e' di fornire la 'byte representation' di differenti
tipi di dato, nello specifico char, int, float e void */

typedef unsigned char *byte_pointer;

// Fornisce ciascun byte in esadecimale
void show_bytes(byte_pointer start, int len) {
    int i;

    for (i=0; i<len; i++) {
        printf("%.2x ", start[i]);
    }

    printf("(%d byte)\n", len);
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main(void) {
    int var_int = 12345;
    float var_flt = 12345.0;
    void *ptr = (int*)12345;
    int val = 0x87654321;
    byte_pointer varp = (byte_pointer) &val;
    int num = 3510593;
    int flt = 3510593.0;
    char ascii_num[] = "123456789";
    const char *ascii_upper = "abcdefghijklmnop";
    const char *ascii_lower = "ABCDEFGHIJKLMNOP";
    short var_sho = 12345;
    short neg_var_sho = -var_sho;

    show_int(var_int);
    show_float(var_flt);
    show_pointer(ptr);

    show_bytes(varp, 1);
    show_bytes(varp, 2);
    show_bytes(varp, 3);
    show_bytes(varp, 4);

    show_int(num);
    show_float(flt);

    /* Da notare che l'unita' decimale 'x' e' rappresentata in esadecimale
    con 0x3x, dove x sta per 1,2,3,4,5,6,7,8,9).

       In esadeciamale le lettere vanno dalla 'a' 0x61, alla 'z' 0x7a, e
    dalla 'A' 0x41 alla 'Z' 0x5a; inoltre non fa differenza l'utilizzo delle
    maiuscole o delle minuscole. */
    show_bytes((byte_pointer)ascii_num, strlen(ascii_num)+1);
    show_bytes((byte_pointer)ascii_upper, strlen(ascii_upper)+1);
    show_bytes((byte_pointer)ascii_lower, strlen(ascii_lower)+1);

    /* Rappresentazione di 12345 in complemento a due, prima il 'positivo'
    poi il suo negativo. E' molto interessante verificare la conversione */
    show_bytes((byte_pointer) &var_sho, sizeof(short));
    show_bytes((byte_pointer) &neg_var_sho, sizeof(short));

    return(EXIT_SUCCESS);
}
