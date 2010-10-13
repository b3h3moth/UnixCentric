#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
   printf(" uid %d\neuid %d\n gid %d\negid %d\n", getuid(), geteuid(), getgid(), getegid());

   if (getuid() == 1001)
      printf("\n user: luca - uid: %d\n", getuid());
   else if (getuid() == 1000)
      printf("\n user: devel - uid: %d\n", getuid());
   else if (getuid() == 0)
      printf("\n user: root - uid: %d\n", getuid());


   return(EXIT_SUCCESS);
}
