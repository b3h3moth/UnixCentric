#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int value;
    value = 0xAABBCCDD;
    
    printf("%#2x %#2x %#2x %#2x\n",
	   *(char *) &value,
	   *(((char *) &value) + 1),
	   *(((char *) &value) + 2), 
       *(((char *) &value) + 3));
}
