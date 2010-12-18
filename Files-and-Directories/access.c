#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h> 

int main(int argc, char *argv[], char *envp[])
{
   char *filename = argv[1];
   int ret_value;

   /* Test di esistenza del file */
   ret_value = access(filename, F_OK);

   if (ret_value == 0)
      printf("Il file '%s' esiste\n", filename);
   else
      printf("Il file '%s' non esiste\n", filename);

   /* Accesso lettura r */
   ret_value = access(filename, R_OK);

   if (ret_value == 0)
      printf("Il file '%s' e' leggibile\n", filename);
   else
      printf("Il file '%s' non e' leggbile\n", filename);

   /* Accesso scrittura w */
   ret_value = access(filename, W_OK);

   if (ret_value == 0)
      printf("Il file '%s' e' scrivibile\n", filename);
   else
      printf("Il file '%s' non e' scrivibile\n", filename);

   /* Accesso esecuzione  x */
   ret_value = access(filename, X_OK);

   if (ret_value == 0)
      printf("Il file '%s' e' eseguibile\n", filename);
   else
      printf("Il file '%s' non e' eseguibile\n", filename);

   return(EXIT_SUCCESS);
}
