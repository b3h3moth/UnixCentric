#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
   int i;
  pid_t pid;

  pid = fork();
  int status;

  while (pid >= 0) {

      if (pid == 0)
	{
	  printf("Child %ld of %ld\n", (long)getpid(), (long)getppid() );
	}
      else if (pid > 0)
	{
	  printf("Parent %ld\n", (long)getpid());
	  kill (pid, 9);
	}

  }
  return (EXIT_SUCCESS);
}
