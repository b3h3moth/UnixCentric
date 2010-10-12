#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[], char *envp[])
{
   char *data;
   time_t ora_e_data;
   
   time(&ora_e_data);
   data = ctime(&ora_e_data);

   printf("%s\n", data);

   return(EXIT_SUCCESS);
}
