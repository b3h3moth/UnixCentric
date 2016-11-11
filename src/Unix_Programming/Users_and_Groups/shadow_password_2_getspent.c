#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <shadow.h>
#include <pwd.h>
#include <sys/types.h>

/*
HEADER    : <shadow.h>
PROTOTYPE : struct spwd *getspent(void);
	        void setspent(void);
	        void endspent(void);
SEMANTICS : la funzione getspent() ritorna un puntatore alla successiva voce 
            dello shadow password database; 
            la funzione setspent() riavvolge lo shadow password database, 
            ricominciando lo scanning del file; 
            la funzione endspent() chiude lo shadow password
	        database dopo che tutte le operazioni si sono concluse.
RETURNS   : Un puntatore alla successiva voce del dello shadow password
            database, in caso di successo; NULL altrimenti
--------------------------------------------------------------------------------
*/

int main(void) {
   uid_t my_uid = getuid();
   struct spwd *sp;

   if (my_uid != 0) {
      fprintf(stderr, "Ops! Only root can read shadow password file.!\n");
      exit(EXIT_FAILURE);
   }

   while ((sp = getspent()) != NULL) {
       printf("     user name: %s\n", sp->sp_namp);
       printf("encrypted pass: %s\n", sp->sp_pwdp);
       printf("  last changes: %ld\n", sp->sp_lstchg);
       printf("           min: %ld\n", sp->sp_min);
       printf("           max: %ld\n", sp->sp_max);
       printf("          warn: %ld\n", sp->sp_warn);
       printf("         inact: %ld\n", sp->sp_inact);
       printf("        expire: %ld\n\n", sp->sp_expire);
   }

   endspent();

   return(EXIT_SUCCESS);
}
