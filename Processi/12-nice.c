#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h> 

int main(int argc, char *argv[], char *envp[])
{

   printf("getpriority %d\n", getpriority(1, 1996));

   return(EXIT_SUCCESS);
}
