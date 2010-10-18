#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
   int N1, N2, nread;
   char buf;

   if (argc < 3)
   {
      printf("Uso: %s <int><int> \n", argv[0]);
      exit(1);
   }

   N1 = atoi(argv[1]);
   N2 = atoi(argv[2]);

   while ( (nread = read(0, &buf, 1)) > 0)
      if ( ((int)buf >= N1) && ((int)buf <= N2) )
      	 write(1, &buf, 1);

   return(EXIT_SUCCESS);
}
