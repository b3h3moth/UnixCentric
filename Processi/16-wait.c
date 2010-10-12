#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
   int i, status;
   pid_t pid;
   pid = fork();


   if (pid < 0) {
      printf("err........\n");
      exit(13);
   }

   for (i=0; i<10; i++) {
      if (pid == 0)
      	 printf("sono il figlio\n");
      else {
      	 printf("sono il padre\n");
      }
   }
   printf("---\n");

   for (i=0; i<10; i++) {
      if (pid == 0)
      	 printf("sono il figlio\n");
      else {
      	 wait(&status);
      	 printf("sono il padre\n");
      }
   }

   

   return(EXIT_SUCCESS);
}
