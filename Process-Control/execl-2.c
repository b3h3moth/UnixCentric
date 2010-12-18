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
#define MAXSTR 256

int main(int argc, char *argv[])
{
   pid_t pid;
   int wait_shell_process;
   /* La execlp() riceve un carattere che proprio non vuole 
    * considerare, e restituisce un errore; di seguito vi e' un metodo per
    * togliere questo carattere in piu', ma comunque ci sono problemi.
    *
    * lascio l'esempio poiche' tecnicamente e' splendido
   char command[MAXSTR], options[MAXSTR];
   int n1, n2;
   char *c1, *c2;
   int i;

   printf("Comando: ");
   fgets(command, sizeof(stdin), stdin);
   fflush(NULL);
   printf("Opzione: ");
   fgets(options, sizeof(stdin), stdin);
   n1 = strlen(command), n2 = strlen(options);
   printf("command:%d options:%d\n", n1,n2);
   c1 = malloc(n1* sizeof(char));
   c2 = malloc(n2* sizeof(char));
   strcpy(c1,command), strcpy(c2, options);
   for (i=0; i<n1; i++) {
      if (c1[i] == '\n')
      	 c1[i] = '\0';
   }
   for (i=0; i<n2; i++) {
      if (c2[i] == '\n')
      	 c2[i] = '\0';
   }
   printf("%s %s\n", c1, c2);
   */

   if (argc < 3) {
      fprintf(stderr, "<Uso: comando + opzione> Error: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
   }


   /* Si crea un sottoprocesso */
   pid = fork();

   if (pid < 0) {
      fprintf(stderr, "Errore nella fork(): %s\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   /* Processo figlio */
   if (pid == 0) {
      printf("SHELL v.0.0.99\n");
      if ( (execlp(argv[1], argv[2], NULL)) < 0) {
      	 fprintf(stderr, "Errore nella execlp(): %s\n", strerror(errno));
	 exit(13);
      }
   } else {
      wait(&wait_shell_process);
      /* Processo padre */
      printf("Eseguo il padre\n");
   }

   return(EXIT_SUCCESS);
}
