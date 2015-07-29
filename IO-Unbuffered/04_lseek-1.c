#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 
#include <string.h> 

#define MAX_BUF     1024
#define PERMS       0644
#define OFFSET      32

/* Legge il contenuto del file 'input_file', dopodiche' il file-offset viene 
aggiornato di OFFSET bytes rispetto all'inizio - in pratica rimuovera' la prima
riga che nel mio file corrisponde a OFFSET byte -, da questo punto si copiera'
tutto il contenuto sul file 'output_file'.
*/

int main(int argc, char *argv[], char *envp[])
{
   int fd1, fd2;
   char *input_file = "/etc/passwd";
   char *output_file = "new_passwd.txt";
   char buf[MAX_BUF];
   ssize_t num_read;

   if ( (fd1 = open(input_file, O_RDONLY)) < 0) {
      printf("Err. apertura %s\n", input_file);
      exit(EXIT_FAILURE);
   }

   if ( (fd2 = open(output_file, O_RDWR | O_CREAT, PERMS)) < 0) {
      printf("Err. apertura %s\n", input_file);
      exit(EXIT_FAILURE);
   }

   /* Il file-offset del file in lettura e' ora aggiornato al byte 70 */
   if (lseek(fd1, OFFSET, SEEK_SET) == -1) {
      printf("Err. lseek()\n");
      exit(EXIT_FAILURE);
   }

   /* Legge input_file dal byte OFFSET */
   if ((num_read = read(fd1, &buf, MAX_BUF)) < 0) {
      fprintf(stderr, "Err. read\n");
      exit(EXIT_FAILURE);
   }

   /* Scrittura del file 'output_file'.
   La copia riguarda il file di input dall'offset OFFSET, poiche' si sono 
   eliminati dei bytes il valore della write() deve essere aggiornato di
   conseguenza */
   if (write(fd2, &buf, (MAX_BUF - OFFSET)) < 0) {
      fprintf(stderr, "Err. write\n");
      exit(EXIT_FAILURE);
   }

   close(fd1);
   close(fd2);
   
   return(EXIT_SUCCESS);
}
