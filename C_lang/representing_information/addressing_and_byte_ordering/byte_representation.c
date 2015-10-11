#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "show_bytes.h"

/* Lo scopo del programma e' di fornire la 'byte representation' di differenti
tipi di dato, nello specifico char, int, float e void.
*/

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
    double val_db = 12345.0;
    long val_lg = 12345;

    printf("int(%d) %d byte\n", var_int, sizeof(int));
    show_int(var_int);
    printf("float(%.1f) %d byte\n", var_flt, sizeof(float));
    show_float(var_flt);
    printf("pointer(%d) %d byte\n", (int)ptr, sizeof(void *));
    show_pointer(ptr);
    printf("double(%.1f) %d byte\n", val_db, sizeof(double));
    show_double(val_db);
    printf("long(%.ld) %d byte\n", val_lg, sizeof(long));
    show_long(val_lg);

    printf("\npointer(%#x) from %d to %d byte\n", val, 1, 4);
    show_bytes(varp, 1);
    show_bytes(varp, 2);
    show_bytes(varp, 3);
    show_bytes(varp, 4);

    printf("\nint(%d) %d byte\n", num, sizeof(int));
    show_int(num);
    printf("int(%.1f) %d byte\n", (float)flt, sizeof(int));
    show_float(flt);

    /* Da notare che l'unita' decimale 'x' e' rappresentata in esadecimale
    con 0x3x, dove x sta per 1,2,3,4,5,6,7,8,9).

       In esadeciamale le lettere vanno dalla 'a' 0x61, alla 'z' 0x7a, e
    dalla 'A' 0x41 alla 'Z' 0x5a; inoltre non fa differenza l'utilizzo delle
    maiuscole o delle minuscole. */
    printf("\n123456789\n");
    show_bytes((byte_pointer)ascii_num, strlen(ascii_num)+1);
    printf("abcdefghijklmnop\n");
    show_bytes((byte_pointer)ascii_upper, strlen(ascii_upper)+1);
    printf("ABCDEFGHIJKLMNOP\n");
    show_bytes((byte_pointer)ascii_lower, strlen(ascii_lower)+1);

    /* Rappresentazione di 12345 in complemento a due, prima il 'positivo'
    poi il suo negativo. E' molto interessante verificare la conversione,
    si lavora col tipo 'short' */
    printf("\nTwo's complement +%d\n", var_sho);
    show_bytes((byte_pointer) &var_sho, sizeof(short));
    printf("Two's complement %d\n", neg_var_sho);
    show_bytes((byte_pointer) &neg_var_sho, sizeof(short));

    return(EXIT_SUCCESS);
}
/* How to compile:
$ gcc   -std=c11 -Wall -pedantic byte_representation.c show_bytes.c
$ clang -std=c11 -Wall -pedantic byte_representation.c show_bytes.c

- show_bytes.h include le dichiarazioni (prototipi) delle funzioni
- show_bytes.c contiene le definizioni delle funzioni
*/
