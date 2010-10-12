#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 3

/*
 * Memoria condivisa
 */
int c = -1;

void *PrintThread(void *thread_id);

int main(int argc, char *argv[])
{
   pthread_t threads[MAX_THREADS];
   int rtn, count;

   for (count=0; count<MAX_THREADS; count++) {
      printf("\nCreazione thread %d\n", count);
      rtn = pthread_create(&threads[count], NULL, PrintThread, (void*) count);
      
      if (rtn) {
      	 printf("Errore nella pthread_create() Codice %d\n", rtn);
	 exit(-1);
      }
   }

   pthread_exit(NULL);

   return(EXIT_SUCCESS);
}

void *PrintThread(void *thread_id)
{
   c++;
   printf("thread_id = %d - c = %d\n", (int)thread_id, c);
   pthread_exit(NULL);
}
