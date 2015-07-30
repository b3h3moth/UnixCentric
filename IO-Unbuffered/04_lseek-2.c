#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define PERMS 0644
#define OFFSET 28

/* Modifica alcuni caratteri della stringa buffer[] */

int main(int argc, char* argv[])
{
  int fd1, num_read;
  char buffer[] = "Advanced Programming in the XXXX Environment.\n";
  char *filename = "test.txt";
  char sub_string[] = "UNIX";

  if ( (fd1 = open(filename, O_RDWR | O_CREAT, PERMS)) == -1) {
     fprintf(stderr, "Err.(%d) open() %s\n", errno, strerror(errno));
     exit(EXIT_FAILURE);
  }

  /*
   scrive il contenuto di buffer nel file 'filename' 
  */
  if (write(fd1, &buffer, sizeof(buffer)) == -1) {
     fprintf(stderr, "Err. write file\n");
     exit(EXIT_FAILURE);
  }

  printf("Before: %s (%d byte)", buffer, strlen(buffer));

  /*
   Sostituzione della stringa XXXX all'interno del file 'filename' con 
   'sub_string', iniziando dall'offset OFFSET 
  */
  if (lseek(fd1, OFFSET, SEEK_SET) == -1) {
     fprintf(stderr, "Err. seek file\n");
     exit(EXIT_FAILURE);
  }
  
  if (write (fd1, sub_string, 4) == -1) {
     fprintf(stderr, "Err. write file\n");
     exit(EXIT_FAILURE);
  }

  /* Ora si sostituisce il carattere di newline '\n' alla fine della stringa
  con il null-byte terminator, carattere di fine stringa */
  if (lseek(fd1, -8, SEEK_END) == -1) {
     fprintf(stderr, "Err.(%d) lseek(): %s\n", errno, strerror(errno));
     exit(EXIT_FAILURE);
  }

  if (write (fd1, "\0", 1) == -1) {
     fprintf(stderr, "Err. write file\n");
     exit(EXIT_FAILURE);
  }
  
  close(fd1);
 
  /*
   Si apre nuovamente il file con la stringa corretta al suo interno
  */
  if ((fd1 = open(filename, O_RDONLY)) == -1) {
     fprintf(stderr, "Err. open file\n");
     exit(EXIT_FAILURE);
  }

  if ( (num_read = read(fd1, &buffer, sizeof(buffer))) == -1 ) {
     fprintf(stderr, "Err. read file\n");
     exit(EXIT_FAILURE);
  }
  
  printf("(%d byte) After: %s", strlen(buffer), buffer);

  close(fd1);

  return(EXIT_SUCCESS);
}
