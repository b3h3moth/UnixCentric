#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/* Lo scopo del programma e' di redirigere lo standard output verso un file,
utilizzando una funzione di duplicazione del file descriptor */

int main(void) {
    int fd;
    char *str;
    char filename[] = "dup.txt";
    int flags = O_WRONLY | O_CREAT;
    int mode = S_IRWXU | S_IXGRP | S_IRWXG | S_IROTH | S_IXOTH;
    
    fd = open(filename, flags, mode);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

  // Redirige lo stdout verso il file aperto dal file descriptor
  if (dup2(fd, 1) < 0) { 
      perror("dup2"); 
      exit(EXIT_FAILURE); 
  }

  printf("Lo standard output va dritto su dupfile.txt\n");

  close(fd);

  printf("Anche quando si chiude il file descriptor '%d'\n", fd);

  putchar('p');
  putchar('u');
  putchar('t');
  putchar('c');
  putchar('h');
  putchar('a');
  putchar('r');
  putchar('\n');

  str = "con fwrite()\n";

  if (fwrite(str, sizeof(char), strlen(str), stdout) < 0 ) {
      perror("fwrite");
      exit(EXIT_FAILURE);
  }

  fflush(stdout); 

  str = "e con write\n";

  if (write(1, str, strlen(str)) < 0) {
      perror("write");
      exit(EXIT_FAILURE);
  }

  return(EXIT_SUCCESS);
}
