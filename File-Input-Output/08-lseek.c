#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define PERMS 0666

/* Modifica alcuni caratteri della stringa buffer[] */

int main(int argc, char* argv[])
{
  int fd1,ret;
  char buffer[] = "La nebbia agli xyzk colli piovigginando sale...\n";
  char *filename = "09-poesia.txt";
  char sostituzione[] = "irti";

  if ( (fd1 = open(filename, O_RDWR | O_CREAT, PERMS)) == -1)
  {
     printf("Errore nell'apertura del file %s\n", filename);
     exit(EXIT_FAILURE);
  }

  /* scrive il contenuto di buffer su file */
  write(fd1, &buffer, sizeof(buffer));

  /* valore di fd */
  printf("Valore del file descriptor fd1 = %d\n", fd1);
  printf("Frase originaria = %s\n", buffer);

  /* posiziona il puntatore del file a partire dal carattere in posizione 15 */
  lseek(fd1, 15, SEEK_SET);
  
  write (fd1, sostituzione, 4);
  
  close(fd1);
  
  fd1 = open(filename, O_RDONLY);

  while ( (ret = read(fd1, &buffer, sizeof(buffer))) )
  {
     printf("byte = %d\nFrase corretta = %s \n", ret, buffer);
  }

  close(fd1);

  return(EXIT_SUCCESS);
}
