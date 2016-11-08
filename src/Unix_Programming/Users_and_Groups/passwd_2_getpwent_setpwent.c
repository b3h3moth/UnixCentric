#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>

/*
Le funzioni setpwent(), getpwent(), endpwent() consentono di scandire il 'file 
password database', che solitamente e' collocato in /etc/passwd, implementato 
grazie alla struttura 'passwd' definita in <pwd.h>.

HEADER    : <pwd.h>
PROTOTYPE : struct passwd *getpwent(void);
            void setpwent(void);
	        void endpwent(void);
SEMANTICS : La funzione getpwent() consente di ottenere il prossimo campo del
            database delle password; 
            la funzione setpwent() riavvolge il database delle password, ossia 
            punta al primo record; 
            la funzione endpwent() chiude tutti i file ad operazioni avvenute.
RETURNS   : La funzione getpwent() ritorna un puntatore alla struttura passwd
            in caso di successo, NULL in caso di errore.
--------------------------------------------------------------------------------
Per compilare il programma con le funzioni getpwent(), setpwent(), endpwent()
e' necessario definire una "feature test macros , nel caso specifico si e' 
optato per _DEFAULT_SOURCE. */

int main(int argc, char *argv[]) {
   struct passwd *pwd;
   char *user_name;

   if (argc < 2) {
      fprintf(stderr, "Usage: %s <user>\n\n"
              "find a <user> in the system.\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   user_name = argv[1];

   // Lista completa di utente e UID
   while ((pwd = getpwent()) != NULL) 
       printf("%6d %s\n", pwd->pw_uid, pwd->pw_name);

   // Per ricominciare la scanning dall'inizio del file
   setpwent();

   // Verifica la presenza di 'user_name' nel file /etc/passwd
   while ((pwd = getpwent()) != NULL)  {
      if (strcmp(user_name, pwd->pw_name) == 0) {
      	 printf("account \'%s\' is in the system.\n", argv[1]);
         break;
      } 
   }
   
   endpwent();
   return(EXIT_SUCCESS);
}
