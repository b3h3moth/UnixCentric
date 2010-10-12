#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main(int argc, char *argv[], char *envp[])
{
   printf("Esempio d'uso di execl()\n");

   execl("/usr/bin/aptitude","aptitude","search","bash",NULL);

   printf("il programma invocato da execl() rimpiazza il processo"\
   	 "padre, per cui, al termine della esecuzione della execl()"\
	 "non si rientra nel processo padre.");

   return(EXIT_SUCCESS);
}
