#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

static int val = 0;

void *PrintThread(void *nothing);

int main(int argc, char *argv[], char *envp[])
{
   pthread_t thread_id;
   int rtn;

   rtn = pthread_create(&thread_id, NULL, &PrintThread, NULL);

   if (rtn != 0)
   {
      printf("thread err. pthread_create(): %d\n", rtn);
      exit(-1);
   }

   while(val < 10)
   {
      printf("Sono nel main: %d\n", val++);
      sleep(1);
   }


   return(EXIT_SUCCESS);
}

void *PrintThread(void *nothing)
{
   while(1)
   {
      printf("Sono nel thread: %d\n", val++);
      sleep(1);
   }
   return(0);
}
