/* 
 * Programma che riceve da linea di comando due parametri:
 * il primo indica il nome di un file F, ed il secondo un numero intero N.
 * Il programma in esecuzione deve creare due processi che in sequenza scrivono
 * N volte su F un dato messaggio che consenta di distinguere il processo che
 * l'ha scritto
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>

#define AUTHOR		"Luca Suriano"
#define MAIL_AUTHOR	"luka@linux.it"
#define PERMS	0755

const char *s1 ="Testo 1\n";
const char *s2 ="Testo 2\n";

int main(int argc, char *argv[])
{
   int i, pid1, pid2, fd, N;

   if (argc != 3) {
      printf("Errore\n");
      exit(-1);
   }

   N = atoi(argv[2]);
   
   if ((fd = open(argv[1], O_WRONLY | O_CREAT, PERMS)) == -1) {
      printf("Errore file\n");
      exit(-1);
   }

   printf("Sono il processo %d\n", getpid());
   
   pid1 = fork();
   if (!pid1) {
      printf("Sono il primo processo %d\n", getpid());
      for (i=0; i<N; i++)
      	 write(fd, s1, strlen(s1));
      close(fd);
   } else {
      pid2 = fork();
      if (!pid1) {
      	 printf("Sono il primo processo %d\n", getpid());
	 for (i=0; i<N; i++)
	    write(fd, s1, strlen(s1));
	 close(fd);
      }
   }



   return(EXIT_SUCCESS);
}
