#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <grp.h>

/*
Le funzioni di seguito elencate consentono di scandire il database dei gruppi,
solitamente collocato in /etc/group e implementato con la struttura 'group'
definita in <grp.h>.

HEADER    : <grp.h>
PROTOTYPE : struct group *getgrent(void);
            void setgrent(void);
	    void endgrent(void);
SEMANTICS : La funzione getpgrent() consente di ottenere il prossimo campo del
            database dei gruppi; la funzione setgrent() apre il file relativo ai
	    gruppi, se non gia' aperto, riavvolgendolo, ossia puntando al primo
	    record; la funzione endgrent() chiude tutti i file ad operazioni 
	    avvenute.
RETURNS   : La funzione getgrent() ritorna un puntatore alla struttura group in
            caso di successo, NULL in caso di errore.
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
   struct group *grp;
   char **tmp_memb;

   setgrent();

   while ((grp = getgrent()) != NULL) {
      printf("  gr_name: %s\n", grp->gr_name);
      printf("gr_passwd: %s\n", grp->gr_passwd);
      printf("   gr_gid: %d\n", grp->gr_gid);
      printf("   gr_mem: " );

      fflush(stdout);
      
      tmp_memb = grp->gr_mem;

      while (*tmp_memb != NULL) {
      	 printf("%s, ", *tmp_memb);
	 tmp_memb++;
      }
      puts("\n");

   }

   endgrent();
   return(EXIT_SUCCESS);
}
