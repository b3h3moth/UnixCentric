#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>


int main(void){
   struct timeval start, end;
   double time_elapsed;
  
   /* Rispetto all'esempio con time() il risultato sara' sicuramente molto
    piu' accurato, poiche' esresso in millisecondi */
   if (gettimeofday(&start, NULL) < 0) {
      fprintf(stderr, "Err.(%s) getting time, start\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   /* Sospendo l'esecuzione del programma per circa 1 secondo e mezzo, espresso
    in millisecondi */
   usleep(1500000);

   if (gettimeofday(&end, NULL) < 0) {
      fprintf(stderr, "Err.(%s) getting time, end\n", strerror(errno));
      exit(EXIT_FAILURE);
   }
   
   time_elapsed = ((((end.tv_sec - start.tv_sec) * 1000000.) +
   	    ((end.tv_usec - start.tv_usec))) / 1000000.);
   
   printf("Tempo trascorso: %f secondi\n", time_elapsed);
   
   return(EXIT_SUCCESS);
}
