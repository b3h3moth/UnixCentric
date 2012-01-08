#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main(void)
{
   /* 
    Le due routine getpid() e getppid() servono per acquisire il PID del 
    current process e il PID del parent process, rispettivamente; da notare che
    il parent process del processo corrente risulta essere la shell in cui si
    esegue il programma.

    Si provi ad eseguire il seguente programma, dopodichè si esegua il comando
    ps e si verifichi il PID della shell corrente, si noterà che che getppid()
    restituirà lo stesso identificativo.
   */
   printf("PID Current process %d\n", getpid());
   printf("PID Parent process %d\n", getppid());

   return(EXIT_SUCCESS);
}
