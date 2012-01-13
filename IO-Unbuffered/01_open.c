#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

/*
 Il termine Unbuffered I/O (definito anche I/O di basso livello) indica che le 
 varie routine (open, read, write, lseek, close, etc...) sono chiamate dirette 
 al sistema operativo e pertanto gestite dal Kernel stesso, inoltre l'accesso
 in lettura e in scrittura sul disco comporta un  "semplice" trasferimento di 
 byte, naturalmente senza formattazione.

 L'I/O Unbuffered non e' standard ISO C, bensi' standard POSIX 1., nonche'
 Single Unix Specification.
*/  

int main(int argc, char *argv[]) {
   int fd;
   char *filename = "/etc/fstab";
  
   /*
    int open(const char *pathnarme, int oflag, mode_t mode);
    - pathname, il file da aprire o creare;
    - oflag; serie di costanti, tra cui (O_RSONLY, O_WRONLY, O_RDWR, etc...);
    - mode; usato solo se il file e' da creare, riguarda i permessi del file 
    stesso.

    Allorquando si crea/apre un file, il kernel rilascia un file descriptor al
    processo, esso e' un intero non negativo che identifica un file aperto; nei 
    sistemi UNIX ad ogni processo eseguito dalla shell sono associati 3 file
    descriptor: standard input 0, standard output 1, standard error 2.

    POISX peraltro ne specifica anche le costanti simboliche in:
    - standard input  = 0 = STDIN_FILENO;
    - stanbdar output = 1 = STDOUT_FILENO;
    - standard error  = 2 = STDERR_FILENO;

    Per poter iniziare a lavorare con un file e' necessario per prima cosa 
    aprirlo, la open() ha questo compito, ed e' peralto in questo momento che 
    sono associati ad esso anche i 3 file descriptor di default; da notare che
    provvede alla localizzazione dell'inode del file che s'intende aprire.

    Nell'esempio, e' un file in sola lettura, pertanto non ha bisogno del terzo 
    argomento.
   */

   if ( (fd = open(filename, O_RDONLY)) < 0) {
      fprintf(stderr, "Err: (%d) - %s\n", errno, strerror(errno));
      exit(EXIT_FAILURE);
   }
   
   /* 
    Si chiude subito il canale di comunicazione stabilito con il kernel, senza
    eseguire alcuna operazione aggiuntiva
   */
   
   close(fd);

   /*
    Nell'esempio il file  e' stato aperto in sola lettura, vi sono tuttavia una
    serie di ulteriori costanti simboliche con cui si sarebbe potuta gestire 
    l'apertura, o la scrittura, del file, alcune di esse sono:
    - O_RDONLY - Apre il file in lettura;
    - O_WRONLY - Apre il file in scrittura;
    - O_RDWR   - Apre il file il lettura e scrittura;
    - O_CREAT  - Se il file non esiste sara' creato;
    - O_EXCL   - E' utilizzato in concomitanza con O_CREAT, in modo che se il
                 file dovesse essere gia' presente nel filesystem, ritornerebbe
		 un errore EEXIST, ossia file gia' esistente nel filesystem.

    Nell'esempio che segue si simulera' proprio il il caso appena citato.
   */

   if ((fd = open("01_open.c", O_CREAT | O_EXCL, 0644)) < 0) {
      fprintf(stderr, "Err: (%d) - %s\n", errno, strerror(errno));
      exit(EXIT_FAILURE);
   }

   close(fd);

   return(EXIT_SUCCESS);
}
