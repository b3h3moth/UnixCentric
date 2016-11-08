#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>

/*
Le funzioni di seguito elencate consentono di scandire il "password database",
solitamente collocato in /etc/passwd e implementato con la struttura 'passwd'
definita in <pwd.h>.

HEADER    : <pwd.h>
PROTOTYPE : struct passwd *getpwent(void);
            void setpwent(void);
	        void endpwent(void);
SEMANTICS : La funzione getpwent() consente di ottenere il prossimo campo del
            database delle password; la funzione setpwent() riavvolge il 
	        database delle password, ossia punta al primo record; la funzione 
	        endpwent() chiude tutti i file ad operazioni avvenute.
RETURNS   : La funzione getpwent() ritorna un puntatore alla struttura passwd
            in caso di successo, NULL in caso di errore.
--------------------------------------------------------------------------------
Per compilare il programma con le funzioni getpwent(), setpwent(), endpwent()
e' necessario definire "feature test macros , nel caso specifico si e' optato 
per _DEFAULT_SOURCE. */

int main(int argc, char *argv[]) {
   struct passwd *ptr;
   char *user_name;

   if (argc < 2) {
      fprintf(stderr, "Usage: %s <user>\n\n"
              "Find if <user> is in the system, checking a correspondence \n"
		      "into the /etc/passwd file.\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   user_name = argv[1];

   setpwent();

   if ((ptr = getpwent()) != NULL) {
      if (strcmp(user_name, ptr->pw_name) == 0) {
      	 printf("account \'%s\' is in the system.\n", argv[1]);
      } else
          printf("account \'%s\' is not in the system.\n", argv[1]);
   }
   
   endpwent();
   return(EXIT_SUCCESS);
}
