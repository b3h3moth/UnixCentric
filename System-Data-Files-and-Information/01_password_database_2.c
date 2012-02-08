#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>

/*
Le funzioni di seguito elencate consentono di scandire il "password database",
solitamente collocato in /etc/passwd e implementato con la struttura 'passwd'
definita in <pwd.h>.

HEADER    : <pwd.h>
PROTOTYPE : struct passwd *getpwent(void);
            void setpwent(void);
	    void endpwent(void);
SEMANTICS : La funzione getpwent() consente di ottenere il campo successivo
            del file /etc/passwd; la funzione setpwent() riavvolge il 
	    "password database"; la funzione endpwent() chiude il "password 
	    database" dopo che tutte le operazioni sono state eseguite.
RETURNS   : La funzione getpwent() ritorna un puntatore alla struttura passwd in
            caso di successo, NULL in caso di errore.
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
   struct passwd *ptr;
   char *user_name;

   if (argc < 2) {
      fprintf(stderr, "Uso: %s <utente>\n\n"
      	              "Cerca se <utente> e' presente nel sistema, verificando\n"
		      "una corrispondenza nel file /etc/passwd\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   user_name = argv[1];

   setpwent();

   while ((ptr = getpwent()) != NULL) {
      if (strcmp(user_name, ptr->pw_name) == 0) {
      	 printf("utente \'%s\' presente nel sistema\n", argv[1]);
      	 break;
      }
   }
   
   endpwent();
   return(EXIT_SUCCESS);
}
