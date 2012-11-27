#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 32

int main(int argc, char **argv, char **envp) {
   char buf[MAX_STR];
   int value;
   strcpy(buf,"31337standard library 38928");

   printf("%s\n", buf);

   /* atoi() converte la porzione iniziale di una stringa in un intero
	*/
   value = atoi(buf);
   printf("%d\n", value);


   return(EXIT_SUCCESS);
}
