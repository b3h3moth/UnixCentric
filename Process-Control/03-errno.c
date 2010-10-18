#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>  
#include <errno.h> 

int main(int argc, char *argv[], char *envp[])
{
   char *filename = "/etc/passwd";
   int fd = open(filename, O_RDONLY);

   if (fd == 0)
      printf("errno = %d\nstrerror %s\n", errno, strerror(errno));

   return(EXIT_SUCCESS);
}
