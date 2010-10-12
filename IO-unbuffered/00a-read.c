#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 
#include <string.h>
#define MAXSTR 1024

int main(int argc, char *argv[], char *envp[])
{
   int fd;
   int rd;
   char filename[] = "/etc/passwd";
   char buf[MAXSTR];
   fd = open(filename, O_RDONLY);

   if (fd == -1)
      printf("Err.\n");

   if ( (rd = read(fd, buf, MAXSTR)) != -1)
   	 write(fileno(stdout), buf, strlen(buf));

   printf("\n");

   return(EXIT_SUCCESS);
}
