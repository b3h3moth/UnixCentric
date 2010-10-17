#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv) {
   extern int errno;
   int fd;

   if ( (fd = open("file.txt", O_RDONLY)) < 0) {
      if (errno == ENOENT) {
	  	  puts("il file file.txt non esiste");
		  exit(13);
	  }
	  printf("errore %d\n", errno);
	  exit(13);
   }

   return(EXIT_SUCCESS);
}
