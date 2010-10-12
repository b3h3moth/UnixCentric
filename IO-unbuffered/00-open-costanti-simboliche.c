#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
   int fd;
   char *filename = "00.txt";
   char *cazzata = "Il file e' stato letto correttamente.\n";

   if ( (fd = open(filename, O_RDWR | O_CREAT, S_IRWXU)) == -1)
   {
      printf("Impossibile aprire il file\n");
      exit(1);
   }

   write(fileno(stdout), cazzata, strlen(cazzata));

   close(fd);

