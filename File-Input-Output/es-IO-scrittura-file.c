#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define DIMBUF 128
#define PERMESSI 0755

void inserisci(char b[], int fdw);
void stampa(char b[], int fdr);

/*
 * Crea un file, se non esiste, dopodiche' inserira' nel file binario una serie
 * di stringhe, al comando FINE si fermera'
 */

int main(int argc, char *argv[])
{
   char buf[DIMBUF];
   int fd1, fd2;
   char *filename = "file.txt";

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
