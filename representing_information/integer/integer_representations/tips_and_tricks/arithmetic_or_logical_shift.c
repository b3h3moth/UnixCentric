#include <stdio.h>
#include <stdlib.h>

/* Si evince come eseguendo un right shift su un operando unsigned possa 
portare ad un undefined behavior */

int main(void) {
    // signed integer
    char buf[sizeof(3+1)];
    int value = 0x80000000;
    int result = snprintf(buf, sizeof(buf), "%u", value >> 24);

    printf("S: %d %#x\n", value, value);
    printf("S: %d %#x\n", result, result);
    printf("S: %s\n", buf);

    // unsigned integer
    char buf2[sizeof(3+1)];
    unsigned int value2 = 0x80000000;
    int result2 = snprintf(buf2, sizeof(buf2), "%u", value2 >> 24);

    printf("U: %d %#x\n", value2, value2);
    printf("U: %d %#x\n", result2, result2);
    printf("U: %s\n", buf2);

    return(EXIT_SUCCESS);
}
