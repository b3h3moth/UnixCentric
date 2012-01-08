#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DIMBUF	128
/*
 * Il programma riceve delle stringhe in input, tali stringhe dopo essere state
 * copiate sullo stdout sono copiate, senza spazi, in un file
 */

void inserisci(char b[], int fdw);
void stampa(char b[], int fdr);

int main(int argc, char *argv[], char *envp[])
{
   char buf[128];
   int fd1, fd2;
   char *filename = "IO-Stringhe.txt";

   if ( (fd1 = open(filename, O_WRONLY | O_CREAT, 0755)) == -1)
   {
      printf("Impossibile aprire il file '%s'\n", filename);
      exit(1);
   }

   inserisci(buf, fd1);
   close(fd1);

   if ( (fd2 = open(filename, O_RDONLY)) == -1)
   {
      printf("Impossibile aprire il file '%s'\n", filename);
      exit(1);
   }

   stampa(buf, fd2);
   close(fd2);

   return(EXIT_SUCCESS);
}

void inserisci(char b[], int fdw)
{
   int i;
   printf("Immettere il testo (digitare END per uscire)\n");

   /* Pulizia del buffer */
   for (i=0; i<DIMBUF; i++)
      b[i] = 0;

   do
   {
      scanf("%s", b);
      if (write(fdw, b, DIMBUF) != DIMBUF)
      	 printf("Errore in scrittura\n");
   } while (strcmp(b, "END"));

}

void stampa(char b[], int fdr)
{
   while( read(fdr, b, DIMBUF) != 0)
      printf("%s\n", b);
}
