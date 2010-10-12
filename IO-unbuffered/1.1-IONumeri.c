/* 
$Author: luca $
$Date: 2010/07/18 15:41:58 $
$Revision: 1.1 $

$Log: 1.1-IONumeri.c,v $
Revision 1.1  2010/07/18 15:41:58  luca
Initial revision

*/

/* 
 * Listato 1.1
 * Scrivere un programma che carichi in un file binario, gestito a basso livello,
 * una serie di numeri interi contenuti in un array
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#define DIMBUF 10
#define PERMESSI 0755
#define AUTHOR		"Luca Suriano"
#define MAIL_AUTHOR	"luka@linux.it"

int main(int argc, char *argv[])
{
   int buf[DIMBUF] = {1,2,3,4,5,6,7,8,9,10};
   int i, fd;

   char *filename = "IO-numeri.txt";

   if ((fd = open(filename, O_RDWR | O_CREAT, PERMESSI)) == -1) {
      printf("impossibile aprire %s\n", filename);
      printf("%d", errno);
      exit(1);
   }

   /* ciclo di caricamento in fd */
   for (i=0; i<DIMBUF; i++) 
      write(fd, &buf[i], sizeof(int));
   close(fd);

   /* legge gli interi dal file e  li stampa in output */
   for (i=0; i<DIMBUF; i++) {
      read(fd, &buf, sizeof(int));
      printf("%d\n", buf[i]);
   }

   close(fd);


   return(EXIT_SUCCESS);
}


/* 
EOF $Source: /home/luca/devel/programming-Posix/esercizi_Linuguaggio-C-in-Ambiente-Linux/modulo-1-gestione-file-a-basso-livello/1.1-IONumeri.c,v $ 
*
