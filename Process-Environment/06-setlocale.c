#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
   int categoria;
   char *stringa;

   system("clear");

   if ( (setlocale(LC_ALL, "")) == NULL) {
      printf("exit now.\n");
   }

   printf("%s", stringa);

   return(EXIT_SUCCESS);
}

