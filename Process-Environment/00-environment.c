#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM 10

int main(int argc, char* argv[]) {
   
    int i;

    printf("Nome del programma: %s\n", argv[0]);
    printf("E' stato invocato con %d elementi\n", argc);

    if (argc > 1) {
		printf("Gli argomenti sono: \n");
		for (i=0; i<argc; ++i)
			printf("%s\n", argv[i]);
    }

    return(EXIT_SUCCESS);
}
