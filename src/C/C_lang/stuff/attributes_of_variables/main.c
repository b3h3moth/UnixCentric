#include <stdio.h>
#include <stdlib.h>

typedef struct structure1 {
    char arr[2];        // 2 byte   +   2 extra bytes
    int val1;           // 4 byte
    int val2;           // 4 byte
} T1;

/* The size of a structure can be determined by sizeof(struct type).
   The C compiler will calculate the size in total number of bytes of the
   structure. Due to memory alignment constraints, the C compiler may pad some
   of the ﬁelds of a structure with extra bytes.
*/

typedef struct structure2 {
    char arr[2];        // 2 byte
    int val1;           // 4 byte
    int val2;           // 4 byte
} __attribute__((packed)) T2;

/* The user may deﬁne C structures with the `packed` attribute, which prevents
   the C compiler from padding the ﬁelds with extra bytes.

   The `packed` attribute specifies that a variable or structure field should h
   ave the smallest possible alignment—one byte for a variable, and one bit for
   a field, unless you specify a larger value with the aligned attribute.

   In this case, the size of the `T2` structure will be 10 bytes.
   Without the packed attribute, it would be 12 bytes because the C compiler
   would pad the name ﬁeld with 2 extra bytes, making every object a multiple
   of 4 bytes for memory alignment.
*/

int main(void) {
    T1 myst1;
    T2 myst2;
    int size1 = sizeof(myst1);
    int size2 = sizeof(myst2);

    printf("size of myst1 structure: %d\n", size1);     /* 12 byte */
    printf("size of myst2 structure: %d\n", size2);     /* 10 byte */

    return(EXIT_SUCCESS);
}
