#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *str = (const char[]){"Take a Walk on The WIld Side"};
    printf("%s\n", str);

    return(EXIT_SUCCESS);
}
