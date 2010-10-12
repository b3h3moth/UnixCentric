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

#define PERMS	0755
#define TESTO_PID_1	"Testo processo 1"
#define TESTO_PID_2	"Testo processo 2"

int main(int argc, char *argv[])
{
   pid_t pid1, pid2;
   int fd, i;

   if (argc < 3) {
      fprintf(stderr, "Uso: %s arg1 arg2\n[arg1 e' un nome di un file, arg2 e' un intero\n", argv[0], strerror(errno));
      exit(EXIT_FAILURE);
   }

   if ((fd = open(argv[1], O_WRONLY | O_CREAT, PERMS)) == -1) {
      fprintf(stderr, "Errore %s\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   pid1 = fork();
   pid2 = fork();

   if (pid1 < 0) {
      fprintf(stderr,"Errore nella fork(): %s\n", strerror(errno));
      exit(EXIT_FAILURE);
   } else if (!pid1) {
      for (i=0; i<atoi(argv[2]); i++) {
      	 write(fd, TESTO_PID_1, sizeof(TESTO_PID_1));
	 break;
      }
   }

   if (pid2 < 0) {
      fprintf(stderr,"Errore nella fork(): %s\n", strerror(errno));
      exit(EXIT_FAILURE);
   } else if (!pid2) {
      for (i=0; i<atoi(argv[2]); i++) {
      	 write(fd, TESTO_PID_2, sizeof(TESTO_PID_2));
	 break;
      }
   }

   close(fd);

   return(EXIT_SUCCESS);
}
