#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
HEADER    : <unistd.h>

PROTOTYPE : int chown(const char *pathname, uid_t owner, gid_t group);
            int fchown(int fd, uid_t owner, gid_t group);
            int lchown(const char *pathname, uid_t owner, gid_t group);

SEMANTICS : Ciascuna di esse cambia i permessi utente (user-ID) e gruppo
            (group-ID)  del file indicato da 'pathname', con i valori indicati
	    in 'owner' per l'utente  e 'group' per il gruppo; le sottili 
	    differenze sono che la funzione fchown() lavora su un file
	    descriptor 'fd', mentre chown() e lchown() su un puntatore a
	    caratteri 'pathname', inoltre la lchown(), allorquando 'pathname'
	    dovesse essere un synbolic link, cambiera' i permessi del symbolic
	    link stesso e non del file a cui punta. 

RETURNS   : 0 In caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
In pratica, sia esso un file sia esso un symbolic link, le funzioni modificano
il proprietario del file, tale processo peraltro puo' essere svolto solo 
dall'amministratore del sistema.

Provare questo programma prima come utente normale poi con sudo.
*/
int main(int argc, char *argv[]) {
   struct stat buf;

   if (argc < 2) {
      fprintf(stderr, "Uso: %s <symbolic link>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   if (lstat(argv[1], &buf) < 0) {
      fprintf(stderr, "Err stat: (%d) - %s\n", errno, strerror(errno));
      exit(errno);
   }

   /* Verifica che si stia lavorando su un symbolic link, dopdiche'
    * imposta i permessi di UserID e GroupID  */
   if (S_ISLNK(buf.st_mode)) {
      if (lchown(argv[1], 1000, 1000) < 0) {
      	 fprintf(stderr, "Err. cannot set User-ID Group-ID to '%s'\n", argv[1]);
	 exit(EXIT_FAILURE);
      }
   } else {
      fprintf(stderr, "Err. '%s' is not a symbolic link\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   return(EXIT_SUCCESS);
}
