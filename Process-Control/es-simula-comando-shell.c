/*
 * Simulare tramite una funzione della famiglika exec(), una esecuzione di un
 * comando shell
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <wait.h>
#include <string.h>

#define AUTHOR		"Luca Suriano"
#define MAIL_AUTHOR	"luka@linux.it"
#define MAXSTR 16


int main(int argc, char *argv[])
{
   pid_t pid;
   int wait_shell_process;
   char command[MAXSTR], options[MAXSTR];
   int i;

   printf("Comando: ");
   fgets(command, sizeof(stdin), stdin);
   printf("Opzione: ");
   fgets(options, sizeof(stdin), stdin);

   for (i=0; i<sizeof(command); i++) {
      if (command[i] == '\n')
      	 command[i] = '\0';
   }
   for (i=0; i<sizeof(options); i++) {
      if (options[i] == '\n')
      	 options[i] = '\0';
   }

   /* Si crea un sottoprocesso */
   pid = fork();

   if (pid < 0) {
      fprintf(stderr, "Errore nella fork(): %s\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   /* Processo figlio */
   if (pid == 0) {
      if ( (execlp(command, options, NULL)) < 0) {
      	 fprintf(stderr, "Errore nella execlp(): %s\n", strerror(errno));
		 exit(EXIT_FAILURE);
      }
   } else {
      wait(&wait_shell_process);
      /* Processo padre */
      printf("Eseguo il padre\n");
   }

   return(EXIT_SUCCESS);
}
