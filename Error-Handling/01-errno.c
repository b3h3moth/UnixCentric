#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv) {
   extern int errno;
   int fd;

   if ( (fd = open("file.txt", O_RDONLY)) < 0) {
      printf("errno = %d\n", errno);
      exit(13);
   }

   return(EXIT_SUCCESS);
}
