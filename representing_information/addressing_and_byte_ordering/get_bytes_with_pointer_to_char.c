#include <stdio.h>

int main() {
    int v, i;
    v = 123;
    printf("%02X %02X %02X %02X\n",
	   *(char *) &v,
	   *(((char *) &v) + 1),
	   *(((char *) &v) + 2), *(((char *) &v) + 3));
};
