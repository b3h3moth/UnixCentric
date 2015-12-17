#include <stdio.h>
#include <stdlib.h>

typedef union unsigned_inspect unsigned_inspect;

union unsigned_inspect {
    unsigned val;
    unsigned char bytes[sizeof(unsigned)];
};

unsigned_inspect twofold = { .val = 0xAABBCCDD, };

int main(void) {
    return(EXIT_SUCCESS);
}
