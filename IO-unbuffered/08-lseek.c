#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 
#include <string.h> 

#define MAXBUF 128

int main(int argc, char *argv[], char *envp[])
{
   int fd1, fd2;
   char *filename = "/etc/passwd";
   char *filename_out = "08-passwd.txt";
   char buf[] = "luka:x";

   if ( (fd1 = open(filename, O_RDONLY)) == -1)
   {
      printf("Err. apertura %s\n", filename);
      exit(1);
   }

   if ( (fd2 = open(filename_out, O_RDWR | O_CREAT, 0755)) == -1)
   {
      printf("Err. apertura %s\n", filename);
      exit(1);
   }

   /* ESEMPIO PESSIMO */
   lseek(fd1, 4, SEEK_SET );
   read(fd1, buf, strlen(buf));
   write(fd2, buf, strlen(buf));

   close(fd1);
   close(fd2);
   
   return(EXIT_SUCCESS);
}
