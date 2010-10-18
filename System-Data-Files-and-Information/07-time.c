#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv, char **envp) {
   time_t cur_time;

   printf("%ld", time(&cur_time)); 

   return(EXIT_SUCCESS);
}
