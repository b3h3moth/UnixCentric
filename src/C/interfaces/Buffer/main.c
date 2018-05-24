#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"

int main(void) {
    Buffer *buf1 = buf_alloc(10, "test1");
    Buffer *buf2 = buf_alloc(10, "test2");
    Buffer *buf3 = buf_alloc(10, "test3");
    Buffer *buf4 = buf_alloc(10, "test4");
    Buffer *buf5 = buf_alloc(10, "test5");
    Buffer *buf6c;

    init_random(buf1);
    print(buf1);
   
    init_str(buf2, "ABCDEFGHIL");
    print(buf2);

    buf_copy(buf3, buf2);
    print(buf3);

    buf_inverse_copy(buf4, buf1);
    print(buf4);

    printf("buf1 has %d occurences of 'A'\n", count(buf1, 'A'));
    printf("buf2 has %d occurences of 'H'\n", count(buf2, 'H'));
 
    concatenate(buf6c, buf1, buf2);
    print(buf6c);

    reset(buf2);
    printf("buf2 has %d occurences of 'H'\n", count(buf2, 'H'));

    buf_dealloc(buf1);
    buf_dealloc(buf2);
    buf_dealloc(buf3);
    buf_dealloc(buf4);
    buf_dealloc(buf5);
    buf_dealloc(buf6c);

    return(EXIT_SUCCESS);
}
