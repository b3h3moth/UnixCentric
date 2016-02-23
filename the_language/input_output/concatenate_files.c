#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

enum { BUF_MAX = 64 };

int main(void) {
    // Inizializza a 0 buf (si sarebbe potuto utilizzare memset())
    char buf[BUF_MAX] = {0};
    return(EXIT_SUCCESS);
}
