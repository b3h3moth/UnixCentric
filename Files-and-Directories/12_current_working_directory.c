#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define MAX_PATH 256

void get_working_dir(void);

/*
HEADER    : <unistd.h>
PROTOTYPE : int chdir(const char *pathname);
SEMANTICS : Cambia la directory di lavoro in 'pathname'
RETURNS   : 0 In caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
HEADER    : <unistd.h>
PROTOTYPE : int fchdir(int fd);
SEMANTICS : Cambia la directory di lavoro tramite il file descriptor 'fd'
RETURNS   : 0 In caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
HEADER    : <unistd.h>
PROTOTYPE : char *getcwd(char *buf, size_t size);
SEMANTICS : Legge il pathname della current working directory; restituisce il
            pathname assoluto mediante la stringa 'buf', di dimensione 'size'
RETURNS   : buf in caso di successo, NULL in caso di errore
--------------------------------------------------------------------------------
Quando un utente si logga in un sistema UNIX, la current working directory - 
directory di lavoro corrente - iniziale e' indicata dal sesto campo di 
/etc/passwd, ossia la HOME directory dell'utente stesso.

Ad ogni processo e' associata una current working directory, che sta ad indicare
il pathname relativo, essa, via terminale, puo' essere cambiata mediante il 
comando cd, oppure stampata in output con il comando pwd.

Nota: La funzione fchdir() non e' parte delle specifiche POSIX.1, ma e' una 
estensione XSI della SUS.
*/


int main(int argc, char *argv[]) {

   get_working_dir();

   /* Mi sposto nella parent directory */
   if (chdir("..") < 0) {
      fprintf(stderr, "Err.:(%d) - %s: \"..\"\n", errno, strerror(errno));
      exit(EXIT_FAILURE);
   }

   get_working_dir();

   return(EXIT_SUCCESS);
}

void get_working_dir(void) 
{
   char buf[MAX_PATH];

   /* La directory di lavoro corrente in forma assoluta */
   if (getcwd(buf, sizeof(buf)) == NULL) {
      fprintf(stderr, "Err.:(%d) - %s: current working directory\n", 
      	    errno, strerror(errno));
      exit(EXIT_FAILURE);
   }
   printf("%s\n", buf);
}
