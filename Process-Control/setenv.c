#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
   char new_var[] = "E-MAIL";
   char new_value[] = "l.s@cryptolab.net";

   
   if ( getenv(new_var) == NULL)
   {
      putenv(new_var);
      setenv(new_var, new_value, 1);
      printf("%s\n", getenv(new_var));
   }
   else
      printf("Err...\n");

   return(EXIT_SUCCESS);
}
