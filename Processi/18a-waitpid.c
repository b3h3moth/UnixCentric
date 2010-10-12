#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
   pid_t cpid, w;
   int status;

   cpid = fork();

   if (cpid <0) {
      perror("fork");
      exit(13);
   }

   if (cpid == 0) {
      printf("Processo figlio %ld in esecuzione, processo padre %ld\n", 
      	    (long)getpid(), (long)getppid());

      if (argc == 1)
      	 pause();	/* Aspetta i segnali */
      _exit(atoi(argv[1]));
   } else {
      do {
      	 w = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
	 if (w == -1) {
	    perror("waitpid");
	    exit(EXIT_FAILURE);
	 }
	 
	 if (WIFEXITED(&status)) {
	    printf("Stato di uscita %d\n", WEXITSTATUS(status));
	 } else if (WIFSIGNALED(&status)) {
	    printf("Killato dal segnale %d\n", WTERMSIG(status));
	 } else if (WIFSTOPPED(&status)) {
	    printf("Stoppato dal segnale %d\n", WSTOPSIG(status));
	 } else if(WIFCONTINUED(&status)) {
	    printf("continuato\n");
	 }
      } while (!WIFEXITED(&status) && WIFSIGNALED(&status));
      exit(EXIT_SUCCESS);
   }

   return(EXIT_SUCCESS);
}
