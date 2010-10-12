#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>	/* Gestione errori */
#include <unistd.h>

#define DIMBUF 10

int main(int argc, char *argv[], char *envp[])
{
   int buf[DIMBUF] = {0,1,2.3,4,5,6,7,8,9};
   int i, fd1, fd2;

   char *filename = "IO-numeri.txt";

   if ( (fd1 = open(filename, O_WRONLY | O_CREAT, 0755)) == -1)
   {
      printf("Impossibile aprire il file %s\n", filename);
      printf("%d", errno);
      exit(1);
   }

   /* Ciclo di caricamento in fd1 */
   for (i=0; i<DIMBUF; i++)
   {
      write(fd1, &buf[i], sizeof(int)); /* sizeof(buf[i]) */
      close(fd1);
   }

   if ( (fd2 = open(filename, O_RDONLY)) == -1)
   {
      printf("Impossibile aprire il file\n");
      exit(1);
   }

   for (i=0; i<DIMBUF-1; i++)
   {
      read(fd2, &buf, sizeof(buf[i]));
      printf("%d\n", buf[i]);
   }

   close(fd1);

   return(EXIT_SUCCESS);
}
