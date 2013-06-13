#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 
#include <string.h>

#define MAX_TRY 3

void printout(char *s);

int main(int argc, char *argv[], char *envp[])
{
   char *filename = argv[1];
   int fd, try = 1;
   struct flock lock;

   printout("Apertura");

   if ((fd = open(filename, O_WRONLY)) == -1)
   {
      printf("Errore in open())\n");
      exit(1);
   }

   /* Azzera/inizializza l'aria di memoria per flock */
   memset(&lock, 0, sizeof(lock));
   printout("Sto bloccando....");

   /* Setta il write lock */
   lock.l_type = F_WRLCK;

   /* Imposta il lock in scrittura
    * ed effettua MAX_TRY tentativi di accesso, 
    * cadenzati ogni 2 secondi */
   while( (fcntl(fd, F_SETLK, &lock) < 0) && (try <= MAX_TRY))
   {
      printf("\ntry %d...", try);
      try++;
      sleep(2);
   }

   if (try > MAX_TRY)
   {
      printout("File occupato...riprovare\n");
      exit(1);
   }

   printout("Bloccato....");

   getchar();
   lock.l_type = F_UNLCK;
   fcntl(fd, F_SETLKW, &lock);
   close(fd);


   return(EXIT_SUCCESS);
}

void printout(char *s)
{
   printf("%s\n", s);
}
