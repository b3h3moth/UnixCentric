#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *AssegnaMemoria(char *buf, int val);

int main(int argc, char *argv[])
{
	char def_string[] = "C language programming";
	char *buffer;
	int val = strlen(def_string)+1;

	buffer = AssegnaMemoria(buffer, val);
	strcpy(buffer, def_string);
	buffer[--val] = '\0';

	printf("strlen(default string): %d - %s\n", val, def_string);
	printf("    strlen(new string): %d - %s\n", strlen(buffer), buffer);
	
	return(EXIT_SUCCESS);
}

/* Ritorna l'indirizzo di memoria ampio per contenere esattamente un vettore di
 * caratteri di <val> dimensioni */
char *AssegnaMemoria(char *buf, int val)
{
	return buf = calloc(val,  sizeof(char));
}
