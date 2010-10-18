#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   char c;

   /*
    * Come si puo notare, il parametro della read che prevederebbe la lunghezza
    * del buffer, è di 1, ciò vuol dire che la lettura dell'input sarà carattere
    * oer carattere.
    *
    * Codice estremamente efficiente
    */
   while (read(0, &c, 1) > 0)
      printf("%c", c);

   return(EXIT_SUCCESS);
}
