/* Crea una directory; il nome e' fornito dall'utente in input */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LEN 20

typedef struct {
   char nome[MAX_LEN];
   mode_t modo;
} Directory;

int main() {

   Directory new_dir;
   new_dir.modo = 0700;

   printf("Setta il nome della directory: ");
   scanf("%19s", new_dir.nome);

   mkdir(new_dir.nome, new_dir.modo);

   return(EXIT_SUCCESS);
}

