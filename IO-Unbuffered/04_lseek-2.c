#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define PERMS 0644
#define SEEK_POS 28

/* Modifica alcuni caratteri della stringa buffer[] */

int main(int argc, char* argv[])
{
  int fd1, ret;
  char buffer[] = "Advanced Programming in the XXXX environment\n";
  char *filename = "test.txt";
  char sub_string[] = "UNIX";

  if ( (fd1 = open(filename, O_RDWR | O_CREAT, PERMS)) == -1) {
     fprintf(stderr, "Err. open file %s\n", filename);
     exit(EXIT_FAILURE);
  }

  /*
   scrive il contenuto di buffer nel file 'filename' 
  */
  if (write(fd1, &buffer, sizeof(buffer)) < 0) {
     fprintf(stderr, "Err. write file\n");
     exit(EXIT_FAILURE);
  }

  printf("Contenuto iniziale del file: %s\n", buffer);

  /*
   Sostituzione della stringa XXXX all'interno del file 'filename' con 
   'sub_string', iniziando dall'offset SEEK_POS 
  */
  if (lseek(fd1, SEEK_POS, SEEK_SET) < 0) {
     fprintf(stderr, "Err. seek file\n");
     exit(EXIT_FAILURE);
  }
  
  if (write (fd1, sub_string, 4) < 0) {
     fprintf(stderr, "Err. write file\n");
     exit(EXIT_FAILURE);
  }
  
  close(fd1);
  
  /*
   Si apre nuovamente il file con la stringa corretta al suo interno
  */
  if ((fd1 = open(filename, O_RDONLY)) < 0) {
     fprintf(stderr, "Err. read file\n");
     exit(EXIT_FAILURE);
  }

  while ( (ret = read(fd1, &buffer, sizeof(buffer))) )
     printf("%s: %d byte\nConteneuto dopo la sostituzione = %s", filename, ret, buffer);

  close(fd1);

  return(EXIT_SUCCESS);
}
