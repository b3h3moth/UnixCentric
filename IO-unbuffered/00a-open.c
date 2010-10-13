#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
   system("clear");
   char *filename="/etc/passwd";
   int apro_file, n;
   char buf[10];
   
   if ( (apro_file = open(filename, O_RDONLY)) < 0) {
      printf("Cannot open file ...");
      exit(1);
   }

   /* Scrive il file /etc/passwd in input; 
    * il parametro 1 della write() sta per standard output
    */
   while ( (n = read(apro_file, buf, 10)) > 0) {
      write (1,buf,n);
   }

   printf(".");


   return(EXIT_SUCCESS);
}

