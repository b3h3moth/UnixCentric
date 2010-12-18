#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <pthread.h>

#define NUM_THREADS 10

void *print_hello_world(void *tid);

int main(int argc, char *argv[])
{
   /* Il programma principale crea
    * 10 thread ed esce
    */
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   int status, i;
   pthread_attr_init(&attr);

   for (i=0; i<NUM_THREADS; i++) {
      printf("main here. Creating thread %d0", i);
      status = pthread_create(&threads[i], &attr, print_hello_world, (void *)i);

      if (status != 0) {
      	 printf("OOoops pthread_create returned error code %d0", status);
	 exit(-1);
      }
   }

   return(EXIT_SUCCESS);
}

void *print_hello_world(void *tid)
{
   /*int i = (int)tid;*/
   /* Stampa l'ID del thread ed esce */
   printf("Hello World from thread %d0", (int)tid);
   pthread_exit(NULL);
}
