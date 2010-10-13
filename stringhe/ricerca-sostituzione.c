#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void censor(char str[]);

int main(int argc, char *argv[])
{
   /*
   char str[] = "bigfoot";
   censor(str);
   printf("%s\n", str);
   */
   int i;

   if (argc <= 1)
   {
      printf("Inserscici una stringa per cortesia\n");
      exit(EXIT_FAILURE);
   }

   for (i=0; i<argc; i++)
   {
      censor(argv[i]);
      printf("[%2d - %15s]\n", i, argv[i]);
   }

   return(EXIT_SUCCESS);
}

/*
 * la funzione censor() riceve una stringa e, controllando la stringa stessa
 * carattere per carattere, verifica la presenza di una specifica stringa,
 * qualora la trovasse sostituisce ciascun carattere con 'x'.
 */
void censor(char str[])
{
   int i;

   /* funziona anche con:
    * int i = 0;
    * for (; *str++; i++)
    * ...
    */
   for (i=0; str[i] != '\0'; i++)
   {
      if (str[i] == 's' && str[i+1] == 'o' && str[i+2] == 's')
      	 str[i] = str[i+1] = str[i+2] = 'x';
   }
}
