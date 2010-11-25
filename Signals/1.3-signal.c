#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void inthandler();	/* gestore segnale interrupt */
void quithandler();	/* gestore segnale quit */

int main(int argc, char *argv[])
{
   signal(SIGINT, inthandler);		/* registrazione degli handler */
   signal(SIGQUIT, quithandler);

   printf("Ctrl-C disabilitato - Usare Ctrl-\\ per uscire\n");
   while(1);

   return(EXIT_SUCCESS);
}

void inthandler()
{
   printf("Interrupt Ctrl-C\n");
   signal(SIGINT, inthandler);
}

void quithandler()
{
   printf("Ctrl-\\ - Uscita\n");
   exit(EXIT_SUCCESS);
}
