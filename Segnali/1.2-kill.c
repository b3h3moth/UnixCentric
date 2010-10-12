#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define AUTHOR		"Luca Suriano"
#define MAIL_AUTHOR	"luka@linux.it"

int main(int argc, char *argv[])
{
   kill (getpid(), SIGKILL);
   kill (getppid(), SIGKILL);

   return(EXIT_SUCCESS);
}
