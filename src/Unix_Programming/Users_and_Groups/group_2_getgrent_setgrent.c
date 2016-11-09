#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <grp.h>

/*
Le funzioni setgrent(), getgrent(), endgrent() consentono di scandire il file
dei gruppi, che solitamente e' collocato in /etc/group, implementato 
grazie alla struttura 'group' definita in <grp.h>.

HEADER    : <grp.h>
PROTOTYPE : struct group *getgrent(void);
            void setgrent(void);
	        void endgrent(void);
SEMANTICS : La funzione getgrent() consente di ottenere il prossimo campo del
            file dei gruppi /etc/group; 
            la funzione setgrent() riavvolge il file dei gruppi, ossia 
            punta al primo record; 
            la funzione endgrent() chiude tutti i file ad operazioni avvenute.
RETURNS   : La funzione getgrent() ritorna un puntatore alla struttura group
            in caso di successo, NULL in caso di errore.
--------------------------------------------------------------------------------
Per compilare il programma con le funzioni getgrent(), setgrent(), endgrent()
e' necessario definire una "feature test macros , nel caso specifico si e' 
optato per _DEFAULT_SOURCE. */

int main(int argc, char *argv[]) {
   struct group *grp;
   char *user_name;

   if (argc < 2) {
      fprintf(stderr, "Usage: %s <user>\n\n"
              "find a <user> in the system.\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   user_name = argv[1];

   // Lista completa di utente e UID
   while ((grp = getgrent()) != NULL) {
       printf("%6d : %s : %1s : ", grp->gr_gid, grp->gr_name, grp->gr_passwd);
       int i = 0;
       while (grp->gr_mem[i]) {
           printf("%s, ", grp->gr_mem[i]);
           i++;
       }
       printf("\n");
   }

   // Per ricominciare la scanning dall'inizio del file
   setgrent();

   // Verifica la presenza di 'user_name' nel file /etc/group
   while ((grp = getgrent()) != NULL)  {
      if (strcmp(user_name, grp->gr_name) == 0) {
      	 printf("\ngroup \'%s\' is in the system.\n", argv[1]);
         break;
      } 
   }
   
   endgrent();
   return(EXIT_SUCCESS);
}
