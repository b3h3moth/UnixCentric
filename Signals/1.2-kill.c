#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[])
{
   kill (getpid(), SIGKILL);
   kill (getppid(), SIGKILL);

   return(EXIT_SUCCESS);
}
