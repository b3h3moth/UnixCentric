/* Crea una directory nella home utente */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_STR 256

int main(int argc, char **argv, char **envp) {
   char buf[MAX_STR];
   char *new_directory = "LinuxProgramming";
   mode_t set_mode = 0755;

   if (argc < 2) {
   	   fprintf(stderr, "Uso: %s <dir_name>\n", argv[0]);
	   exit(EXIT_FAILURE);
   }


   /* Ci si sposta nella $HOME utente */
   if (chdir( getenv("HOME") ) < 0) {
      perror("Errore nell'apertura della directory");
      abort();
   }

   /* mkdir() crea fisicamente la nuova directory */
   if ( (mkdir(argv[1], set_mode)) < 0) {
   	   fprintf(stderr, "Err. nella creazione della directory %s\n", argv[1]);
	   exit(EXIT_FAILURE);
   }

   /* Output della home utente.
	* Per visualizzare le modifiche si e' optato per questa opzione, 
	* sicuramente poco elegante, poiche' altrimenti si sarebbero dovute 
	* utilizzare talune syscall specifiche per la gestione dei processi
	* che non ho ritenuto opportuno prentare in questo contesto.
	*/
   system("ls -l $HOME");
   
   /* La directory viene prima rinominata ... */
   if ( (rename(argv[1], new_directory)) < 0) {
   	   fprintf(stderr, "Err. nel rinominare %s in %s\n", argv[1], new_directory);
   	   exit(EXIT_FAILURE);
   }

   system("ls -l $HOME");
   
   /* E poi eliminata */
   if ( (rmdir(new_directory)) < 0) {
   	   fprintf(stderr, "Err. nella eliminazione di %s\n", new_directory);
   	   exit(EXIT_FAILURE);
   }

   system("ls -l $HOME");

   return(EXIT_SUCCESS);
}
