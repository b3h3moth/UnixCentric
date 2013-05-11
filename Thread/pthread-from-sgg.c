#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/* Questo dato e' condiviso dai thread */
int sum;
/* Il thread */
void *runner(void *param);

int main(int argc, char *argv[], char *envp[])
{
   /* Identificatore del thread */
   pthread_t tid;
   /* insieme di attributi del thread */
   pthread_attr_t attr;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <integer value>\n", argv[0]);
      exit(EXIT_FAILURE);
   }
   
   if (atoi(argv[1]) < 0)
   {
      fprintf(stderr, "%d deve essere >= 0\n", atoi(argv[1]));
      exit(EXIT_FAILURE);
   }

   /* Reperisce gli attributi predefiniti */
   pthread_attr_init(&attr);
   /* Crea il thread */
   pthread_create(&tid, &attr, &runner, argv[1]);
   /* Attende la terminazione del thread 
    * simile ad una wait concettualmente, oserei dire*/
   pthread_join(tid, NULL);

   printf("sum = %d\n", sum);

   return(EXIT_SUCCESS);
}

/* Il thread assume il controllo da questa funzione */
void *runner(void *param)
{
   int i, upper = atoi(param);
   sum = 0;

   for (i=1; i<=upper; i++)
      sum += i;

   pthread_exit(0);
}
