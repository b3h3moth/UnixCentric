#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_STR 256

int main(int argc, char **argv, char **envp) {
   char buf[MAX_STR];
   char *new_directory = "LinuxProgramming";
   mode_t set_mode = 0755;

   /* getcwd() fornisce il path nel quale ci si trova */
   printf("%s\n", getcwd(buf, sizeof(buf)));

   /* Ci si sposta nella $HOME utente */
   if (chdir( getenv("HOME") ) != 0) {
      perror("Errore nell'apertura della directory");
      abort();
   }

   /* mkdir() crea fisicamente la nuova directory */
   mkdir(new_directory, set_mode);
   
   printf("%s\n", getcwd(buf, sizeof(buf)));
   
   /* La directory e' stata creata, ora semplicemente la si visualizza */
   system("ls -l $HOME | grep LinuxProgramming");

   return(EXIT_SUCCESS);
}
