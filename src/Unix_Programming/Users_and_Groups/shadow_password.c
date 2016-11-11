#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <shadow.h>
#include <pwd.h>
#include <sys/types.h>

/*
Nel file /etc/passwd il secondo campo relativo alle password e' solitamente
criptato, per cui contiene solo il carattere 'x', la password invece viene
salvata nel file /etc/shadow, che oltre alla password crittata degli account
contiene anche diverse informazioni relative agli account stessi del sistema.

I file di riferimento sono:
- /etc/shadow
- /etc/gshadow
- /etc/shadow- (backup)

Il file /etc/shadow non e' "world readable", pertanto solo l'utente 'root' puo'
leggerlo, contiene generalmente 9 campi:
1 - user login name;
2 - encrypted password;
3 - date of last password change;
4 - minimum password age;
5 - maximum password age;
6 - password warning period;
7 - password inactivity period;
8 - account expiration date;
9 - reserved field.

Ciascuno dei 9 campi e' definito nella struttura 'spwd' in <shadow.h>:

struct spwd 
{
    char *sp_namp;		
    char *sp_pwdp;	
    long int sp_lstchg;	
    long int sp_min;
    long int sp_max;
    long int sp_warn;	
    long int sp_inact;
    long int sp_expire;	
    unsigned long int sp_flag;
};

Vi sono diverse funzioni che consentono di interagine con le shadow password, 
tra cui:

HEADER    : <shadow.h>
PROTOTYPE : struct spwd *getspnam(const char *name);
            struct spwd *getspent(void);
	        void setspent(void);
	        void endspent(void);
SEMANTICS : La funzione getspnam() ritorna un puntatore alla struttura
            contenente il campo relativo alla corrispondenza 'name'; la funzione
	        getspent() ritorna un puntatore alla prossima voce dello shadow
	        password database; la funzione setspent() riavvolge lo shadow 
	        password database; la funzione endspent() chiude lo shadow password
	        database dopo che tutte le operazioni si sono cosnluse.
RETURNS   : Un puntatore alla struttura spwd in caso di successo, NULL in caso 
            di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
   uid_t my_uid = getuid();
   struct spwd *sp;
   struct passwd *pwd;
   char *user;

   if (my_uid != 0) {
      fprintf(stderr, "Ops! Only root can read shadow password file.!\n");
      exit(EXIT_FAILURE);
   }

   pwd = getpwuid(1000);
   user = pwd->pw_name;

   if ((sp = getspnam(user)) == NULL) {
      fprintf(stderr, "Err. %s reading gestpnam()\n", strerror(errno));
      exit(EXIT_FAILURE);
   }
   printf("     user name: %s\n", sp->sp_namp);
   printf("encrypted pass: %s\n", sp->sp_pwdp);
   printf("last changes: %ld\n", sp->sp_lstchg);

   endspent();

   return(EXIT_SUCCESS);
}
