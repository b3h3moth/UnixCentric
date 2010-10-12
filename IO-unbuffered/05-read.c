#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 
#include <string.h>

#define MAXBUF 32

int main(int argc, char *argv[], char *envp[])
{
   int fd, nread;
   char *filename = "05.txt";
   char buffer[MAXBUF];

   if ( (fd = open(filename, O_RDONLY)) == -1)
   {
      printf("Impossibile aprire il file: %s\n", filename);
      exit(1);
   }

   if ( (nread = read(fd, buffer, sizeof(buffer))) != -1)
   {
      printf("%s", buffer);
   }

   close(fd);
   return(EXIT_SUCCESS);
}
