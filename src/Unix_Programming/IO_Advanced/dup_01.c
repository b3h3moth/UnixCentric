#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

/* Lo scopo del programma e' di aprire un file descriptor, dopodiche' 
duplicarlo mediante le funzioni dup() e dup2(). */

int main(int argc, char *argv[]) {
   int fd, fd2, fd3, nr;
   char buf;

   if (argc < 2) {
      fprintf(stderr, "Uso: %s <filename>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   if ((fd = open(argv[1], O_RDONLY)) < 0) {
      fprintf(stderr, "Err.:(%d) - %s: %s\n", errno, strerror(errno), argv[1]);
      exit(EXIT_FAILURE);
   }

   // Duplicazione del file descriptor 'fd' in 'fd2' mediante dup()
   fd2 = dup(fd);
   
   /* dup() accetta come unico argomento il file descriptor da duplicare,
   dopodiche' e' sufficiente assegnare il valore di ritorno ad una variabile 
   intera. */
   
   // Chiusura del file descriptor iniziale
   close(fd);

   // Duplicazione del file descriptor 'fd2' in 'fd3' mediante dup2()
   dup2(fd2, fd3);

   /* La differenza sostanziale rispetto a dup() e' che non e' neccessario
   alcun un assegnamento, poiche' sara' la dup2() stessa ad eseguire la 
   duplicazione servendosi dei propri argomenti, ovvero il file descriptor da 
   duplicare e il nuovo file descriptor. */

   // Chiusura del secondo file descriptor

   /* Dopo questa sorta di catena di passaggio dei file descpritors, si
   provvede alla lettura del file utilizzando l'ultimo file descriptor 
   duplicato, ovvero 'fd3'. */
   while ((nr = read(fd3, &buf, 1)) > 0) 
      write(STDOUT_FILENO, &buf, nr);

   // Chiusura dell'ultimo file descriptor aperto
   close(fd3);

   return(EXIT_SUCCESS);
}
