#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

/*
 umask() consente di impostare specifici permessi di default da non utilizzare
 allorquando un processo dovesse creare nuovi file, solitamente tale valore e'
 specificato in fase di login a 0022, ovvero i nuovi file non devono contere
 i permessi di scrittura per gruppo e others.

 La funzione non ha valore di ritorno.

 access() permette di verificare l'accesso ai file.
*/

int main(int argc, char *argv[]) {
   int fd1, fd2, verify_fd1;
   char *file_1 = "test1.txt";
   char *file_2 = "test2.txt";

   umask(0);
   if ((fd1 = open(file_1, O_CREAT, RWRWRW)) < 0) {
      fprintf(stderr, "Err. create file\n");
      exit(EXIT_FAILURE);
   }

   umask(022);
   if ((fd2 = open(file_2, O_CREAT, RWRWRW)) < 0) {
      fprintf(stderr, "Err. create file\n");
      exit(EXIT_FAILURE);
   }

   /* Verifica del file */
   if ((verify_fd1 = access(file_1, F_OK)) < 0) {
      fprintf(stderr, "Il file '%s' non esiste \n", file_1);
      exit(EXIT_FAILURE);
   }

   /* Accesso lettura r */
   if ((verify_fd1 = access(file_1, R_OK)) < 0) {
      fprintf(stderr, "Il file '%s' non e' leggibile \n", file_1);
      exit(EXIT_FAILURE);
   } else
      fprintf(stdout, "Il file '%s'  e' leggibile \n", file_1);

   /* Accesso scrittura w */
   if ((verify_fd1 = access(file_1, W_OK)) < 0) {
      fprintf(stderr, "Il file '%s' non e' scrivibile \n", file_1);
      exit(EXIT_FAILURE);
   } else
      fprintf(stdout, "Il file '%s'  e' scriviibile \n", file_1);

   /* Accesso esecuzione  x */
   if ((verify_fd1 = access(file_1, X_OK)) < 0) {
      fprintf(stderr, "Il file '%s' non e' eseguibile \n", file_1);
      exit(EXIT_FAILURE);
   } else
      fprintf(stdout, "Il file '%s'  e' eseguiibile \n", file_1);

   close(fd1);
   close(fd2);

   return(EXIT_SUCCESS);
}
