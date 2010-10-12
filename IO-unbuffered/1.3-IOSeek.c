/* 
$Author: luca $
$Date: 2010/07/27 15:48:44 $
$Revision: 1.1 $

$Log: 1.3-IOSeek.c,v $
Revision 1.1  2010/07/27 15:48:44  luca
Initial revision

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#define AUTHOR		"Luca Suriano"
#define MAIL_AUTHOR	"luka@linux.it"
#define DIMBUF 10
#define PERMESSI 0755

int main(int argc, char *argv[])
{
   int buf[DIMBUF] = {1,2,3,4,5,6,7,8,9,10};
   int i, fd1, pos, num;
   long offset;
   char *filename = "IONumeri.txt";

   if ((fd1 = open(filename, O_WRONLY | O_CREAT, PERMESSI)) == -1) {
      printf("Errore nell'aperura del file %s\n", filename);
      printf("%d\n", errno);
      exit(1);
   }

   write(fd1, &buf, sizeof(buf));
   close(fd1);

   printf("Psozione: ");
   scanf("%d", &pos);

   if ((fd1 = open(filename, O_RDONLY)) == -1) {
      printf("Errore nell'aperura del file %s\n", filename);
      printf("%d\n", errno);
      exit(1);
   }

   offset = (pos-1) * sizeof(int);
   lseek(fd1, offset, SEEK_SET);
   read(fd1, &num, sizeof(int));
   printf("Trovato: %d\n", num);
   close(fd1);

   return(EXIT_SUCCESS);
}


/* 
EOF $Source: /home/luca/devel/programming-Posix/esercizi_Linuguaggio-C-in-Ambiente-Linux/modulo-1-gestione-file-a-basso-livello/1.3-IOSeek.c,v $ 
*/
