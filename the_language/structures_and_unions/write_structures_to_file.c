#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_STR 64

struct rec {
    uint32_t id;
    char alias[MAX_STR];
    char email[MAX_STR];
};

typedef struct rec Record;

int main(void) {
    return(EXIT_SUCCESS);
}
