#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *PrintThread(void *nessuno);

int main(int argc, char *argv[])
{
   pthread_t thread_id;
   int rtn;

   rtn = pthread_create(&thread_id, NULL, &PrintThread, NULL);

   if (rtn) {
      printf("Errore nell'utilizzo del thread %d\n", rtn);
      exit(-1);
   }

   while(1) {
      printf("Sono nel main\n");
   }


   return(EXIT_SUCCESS);
}

void *PrintThread(void *nessuno)
{
   while(1)
      printf("sono nel thread\n");
   return NULL;
}
