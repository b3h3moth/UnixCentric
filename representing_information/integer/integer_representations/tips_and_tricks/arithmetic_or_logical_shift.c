#include <stdio.h>
#include <stdlib.h>

/* Si evince come eseguendo un right shift su un operando unsigned possa 
portare ad un undefined behavior */

int main(void) {
    char buf[sizeof(3+1)];
    unsigned int value = 0x80000000;
    int result = snprintf(buf, sizeof(buf), "%u", value >> 24);

    printf("%d %#x\n", value, value);
    printf("%d %#x\n", result, result);
    printf("%s\n", buf);


    return(EXIT_SUCCESS);
}
