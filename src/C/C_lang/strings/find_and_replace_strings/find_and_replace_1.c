#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 3

void censor(char str[]);

int main(int argc, char *argv[])
{
   /*
   char str[] = "bigfoot";
   censor(str);
   printf("%s\n", str);
   */
   int i;

   if (argc < 2)
   {
      printf("Uso: %s <stringa> \n", argv[0]);
      exit(EXIT_FAILURE);
   }
   
   censor(argv[1]);
   printf("-> [%s]\n", argv[1]);

   return(EXIT_SUCCESS);
}

/*
 * la funzione censor() riceve una stringa e, controllando la stringa stessa
 * carattere per carattere, verifica la presenza di un modello, qualora lo 
 * trovasse sostituirebbe ciascun carattere con 'x'. Il modello peraltro sara'
 * fornito dall'utente e non deve superare i 3 caratteri.
 */
void censor(char str[])
{
   int i, n = 0;
   char buf[MAX_STR];
   
   printf("Inserire il pattern da cercare nella stringa \"%s\": ", str);
   /* saranno validi solo 3 caratteri, il resto sara' scartato */
   scanf("%3s", buf);
   buf[MAX_STR] = '\0';

   printf("Pattern da cercare: \"%s\"\n", buf);

   for (i=0; str[i] != '\0'; i++)
   {
      if (str[i] == buf[n] && str[i+1] == buf[n+1] && str[i+2] == buf[n+2])
      	 str[i] = str[i+1] = str[i+2] = 'x';
   }

   /* funziona anche con:
    * int i = 0;
    * for (; *str++; i++)
    * ...
	*
	* La stringa da cercare e' "sos"
    */
}
