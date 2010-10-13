#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 10

int main(int argc, char* argv[]) {
   
    int i;

    printf("The name of the script is: %s\n", argv[0]);
    printf("The program was invoked with %d elements\n", argc);

    if (argc > 1) {
	printf("The arguments are:\n");
	for (i=0; i<argc; ++i)
	    printf("	%s\n", argv[i]);
    }
	   
    printf("\n");

    for (i=0; i<MAXIMUM; i++) {
	printf("%s\n", argv[i]);
    }
    
    printf("The program was invoked with %d elements\n", argc);

    return(EXIT_SUCCESS);
}
