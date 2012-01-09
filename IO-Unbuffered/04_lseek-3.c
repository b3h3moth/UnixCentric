#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

#define DIMBUF 10
#define PERMESSI 0755

int main(int argc, char *argv[])
{
   int buf[DIMBUF] = {1,2,3,4,5,6,7,8,9,10};
   int i, fd1, pos, num;
   long offset;
   char *filename = "IONumeri.txt";

   if ((fd1 = open(filename, O_WRONLY | O_CREAT, PERMESSI)) == -1) {
      printf("Errore nell'aperura del file %s\n", filename);
      printf("%d\n", errno);
      exit(1);
   }

   write(fd1, &buf, sizeof(buf));
   close(fd1);

   printf("Psozione: ");
   scanf("%d", &pos);

   if ((fd1 = open(filename, O_RDONLY)) == -1) {
      printf("Errore nell'aperura del file %s\n", filename);
      printf("%d\n", errno);
      exit(1);
   }

   offset = (pos-1) * sizeof(int);
   int test = lseek(fd1, offset, SEEK_SET);
   printf("%d\n", test);

   read(fd1, &num, sizeof(int));
   printf("Trovato: %d\n", num);
   close(fd1);

   return(EXIT_SUCCESS);
}
