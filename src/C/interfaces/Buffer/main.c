#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"

int main(void) {
    Buffer *buf1 = buf_alloc(10, "test uno");
    Buffer *buf2 = buf_alloc(10, "test due");

    init_random(buf1);
    buf_print(buf1);

    return(EXIT_SUCCESS);
}
