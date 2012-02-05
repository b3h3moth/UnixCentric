#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUF 10

typedef struct OS {
   int num;
   char name[MAX_BUF];
   int year;
} unix_systems;

/*
HEADER    : <stdio.h>

PROTOTYPE : fread(); fwrite()

SEMANTICS : 

RETURNS   : 0 In caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

int main(void) {
   FILE *fp;
   char *binary_file = "file.bin";
   int i, irc, num_list_elem;
  
   unix_systems list_unix_os[] = {
      {1, "BSD", 1978},
      {2, "SunOS", 1982},
      {3, "Plan9", 1990},
      {4, "Gnu/Hurd", 1991},
      {5, "Linux", 1991}
   };

   unix_systems one_product, *product_ptr = &one_product;
   num_list_elem = sizeof(list_unix_os) / sizeof(unix_systems);

   if ((fp = fopen(binary_file,"w+")) == NULL) {
      fprintf(stderr, "Err.(%d) %s: %s\n", errno, strerror(errno), binary_file);
      exit(EXIT_FAILURE);
   }

   /* Scrive l'array nel file binario puntato da fp */
   irc = fwrite(list_unix_os, sizeof(unix_systems), num_list_elem, fp);

   /* Consente la lettura dall'inizio del file */
   rewind(fp);
   
   printf("  version  year\n");
   for (i=0; i<num_list_elem; i++) {
     fread(product_ptr, sizeof(unix_systems), 1, fp);
     printf("%-2d%-9s%-4d\n",
     	   product_ptr->num, product_ptr->name, product_ptr->year);
   }

   return(EXIT_SUCCESS);
}
