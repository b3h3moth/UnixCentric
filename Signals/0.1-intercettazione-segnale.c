#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h>  
#include <string.h>

#define BUFFER_SIZE 50
char buffer[BUFFER_SIZE];

void gestore_segnale(void);

int main(int argc, char *argv[], char *envp[])
{
   /* Imposta il gestore (handle it) del segnale */
   struct sigaction gestore;
   gestore.sa_handler = gestore_segnale;
   sigaction(SIGINT, &gestore, NULL);

   /* genera il messaggio in uscita */
   strcpy(buffer, " <Control-C> intercettato\n");
   exit(0);

   /* itera fino alla rilevazione del segnale */
   while (1)
      ;

   return(EXIT_SUCCESS);
}

void gestore_segnale(void)
{
   write(STDOUT_FILENO, buffer, strlen(buffer));
   exit(0);
}
