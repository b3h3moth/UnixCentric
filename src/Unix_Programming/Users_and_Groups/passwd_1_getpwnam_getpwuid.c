#define _BSD_SOURCE // uid_t

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pwd.h>
#include <unistd.h>

/*
Il file /etc/passwd contiene diverse informazioni su ciascun account del
sistema, i cui campi, separati dal carattere ':', fanno parte della 
struttura 'passwd' definita in <pwd.h>, per cui ogni riga del file
e' formata dai campi definiti in tale struttura:

struct passwd
{
  char *pw_name;		Username.  
  char *pw_passwd;		password
  __uid_t pw_uid;		User ID.  
  __gid_t pw_gid;		Group ID.
  char *pw_gecos;		Real name.
  char *pw_dir;			Home directory.
  char *pw_shell;		Shell program.
};

Il campo password conterra' unicamente il carattere 'x' qualora fossero state
attivate le 'shadow passwords' - nel file /etc/shadow ci sarebbe la lista 
delle le password crittate di ciascun account -, altrimenti conterrebbe 13 
caratteri per ogni password crittata.

Normalmente le 'shadow password' sono attivate di default.

Le uniche funzioni che POSIX prevede per la modifica del file /etc/passwd sono 
getpwuid() e getpwnam():

HEADER    : <pwd.h>
PROTOTYPE : struct passwd *getpwuid(uid_t uid);
            struct passwd *getpwnam(const char *name);
SEMANTICS : Entrambe restituiscono informazioni relative all'utente specificato,
            alla prima si passa come parametro l'uid utente, alla seconda il
	        nome dell'utente stesso inddicato con 'name'.
RETURNS   : Un puntatore alla struttura passwd in caso di successo, 
            NULL in caso di errore, tutavia qualora l'errore fosse "not found"
            'errno' non muterebbe rispetto al 'NULL', per cui e' necessaria
            una ulteriore verifica sullo stesso 'errno' proprio per 
            distinguere tra i due tipi di errori.
--------------------------------------------------------------------------------
Nota: La struttura 'passwd' utilizzata dalle funzioni in oggetto e' allocata
staticamente, per cui il contenuto e' sovrascritto ad ogni nuova chiamata; esse 
sono utili qualora dovesse servire uno dei campi del file /etc/passwd, se
invece si volesse analizzare il file nel suo complesso dovrebbero essere
utilizzate altre funzioni come getpwent(), setpwent(), endpwent().
*/

int main(void) {
   struct passwd *pd;
   struct passwd *pd2;
   uid_t uid = getuid();
   char *my_name = "mail";
 
   /* Come si puo' notare si passa alla funzione l'uid utente, ottenuto grazie
   alla funzione getuid() */

   pd = getpwuid(uid);
   if (pd == NULL) {
       if (errno == 0) {
           fprintf(stderr, "Account Not Found.\n");
           exit(EXIT_FAILURE);
       } else {
           fprintf(stderr, "Err. getpwuid() failed.\n");
           exit(EXIT_FAILURE);
       }
   } else {
      printf("User name: %s\n", pd->pw_name);
      printf(" Password: %s\n", pd->pw_passwd);
      printf("  User ID: %u\n", pd->pw_uid);
      printf(" Group ID: %u\n", pd->pw_gid);
   }

   /* In questo caso invece si passa alla funzione il nome di un utente, non
   necessariamente dev'essere colui che si e' loggato al sistema */
   pd2 = getpwnam(my_name);
   if (pd2 == NULL) {
       if (errno == 0) {
           fprintf(stderr, "Account Not Found.\n");
           exit(EXIT_FAILURE);
       } else {
           fprintf(stderr, "Err. getpwnam() failed.\n");
           exit(EXIT_FAILURE);
       }
   } else {
      printf("\n     Real name: %s\n", pd2->pw_gecos);
      printf("Home directory: %s\n", pd2->pw_dir);
      printf(" Shell program: %s\n", pd2->pw_shell);
   }

   return(EXIT_SUCCESS);
}
