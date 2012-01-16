#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>


int main(int argc, char **argv, char **envp) {
   char *new_directory = "LinuxProgramming";
   mode_t set_mode = 0755;

   if (argc < 2) {
   	   fprintf(stderr, "Uso: %s <dir_name>\n", argv[0]);
	   exit(EXIT_FAILURE);
   }

   /* mkdir() crea fisicamente la nuova directory */
   if ( (mkdir(argv[1], set_mode)) < 0) {
   	   fprintf(stderr, "Err. nella creazione della directory %s\n", argv[1]);
	   exit(EXIT_FAILURE);
   }
   
   /* La directory viene prima rinominata ... */
   if ( (rename(argv[1], new_directory)) < 0) {
   	   fprintf(stderr, "Err. nel rinominare %s in %s\n", argv[1], new_directory);
   	   exit(EXIT_FAILURE);
   }
   
   /* E poi eliminata */
   if ( (rmdir(new_directory)) < 0) {
   	   fprintf(stderr, "Err. nella eliminazione di %s\n", new_directory);
   	   exit(EXIT_FAILURE);
   }

   return(EXIT_SUCCESS);
}
