/* 
$Author: luca $
$Date: 2010/07/18 19:14:09 $
$Revision: 1.2 $

$Log: 1.2-IOStringhe.c,v $
Revision 1.2  2010/07/18 19:14:09  luca
Aggiunta dell'opzione fflush() nei commenti

Revision 1.1  2010/07/18 18:58:22  luca
Initial revision

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define AUTHOR		"Luca Suriano"
#define MAIL_AUTHOR	"luka@linux.it"
#define DIMBUF 128
#define PERMESSI 0755

void inserisci(char b[], int fdw);
void stampa(char b[], int fdr);

int main(int argc, char *argv[])
{
   char buf[DIMBUF];
   int fd1, fd2;
   char *filename = "IO-stringhe.txt";

   if ((fd1 = open(filename, O_WRONLY | O_CREAT, PERMESSI)) == -1) {
      printf("Impossibile aprire il file %s\n", filename);
      exit(1);
   }

   inserisci(buf, fd1);
   close(fd1);

   if ((fd2 = open(filename, O_RDONLY)) == -1) {
      printf("Impossibile aprire il file %s\n", filename);
      exit(1);
   }

   stampa(buf, fd2);
   close(fd2);

   return(EXIT_SUCCESS);
}

void inserisci(char b[], int fdw)
{
   int i;
   printf("Immettere il testo (digitare 'FINE' per uscire)\n");
   /* Pulisceil buffer */
   for (i=0; i<DIMBUF; i++)
      b[i] = 0;
/* probabilmente fflush(); sarebbe stato più elegante */
   do 
   {
      scanf("%s", b);
      if (write(fdw, b, DIMBUF) != DIMBUF)
      	 printf("Errore in scrittura\n");
   } while(strcmp(b, "FINE"));
}

void stampa(char b[], int fdr)
{
   while (read(fdr, b, DIMBUF) != 0)
      printf("%s\n", b);
}

/*
EOF $Source: /home/luca/devel/programming-Posix/esercizi_Linuguaggio-C-in-Ambiente-Linux/modulo-1-gestione-file-a-basso-livello/1.2-IOStringhe.c,v $ 
*/
