#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 
#include <string.h>

#define MAXSTR 1024

int main(int argc, char *argv[], char *envp[])
{
   int fd, rd;
   char filename[] = "/etc/passwd";
   char buf[MAXSTR];

   if ((fd = open(filename, O_RDONLY)) == -1)
      printf("Err.\n");

   if ( (rd = read(fd, buf, MAXSTR)) != -1)
   	 write(fileno(stdout), buf, strlen(buf));

   printf("\n");

   close(fd);

   return(EXIT_SUCCESS);
}
