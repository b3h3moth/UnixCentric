/* Programma che riceve da linea di comando due argomenti interi; il processo
 * figlio calcola il prodotto mentre il padre calcola la somma. Entrambi stampano
 * il risultato ottenuto.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   int n_arg1, n_arg2, n_tot_somma, n_tot_moltip;
   pid_t pid;

   if (argc < 3) {
      printf("Uso: %s <int1> <int2>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   n_arg1 = atoi(argv[1]);
   n_arg2 = atoi(argv[2]);
   pid = fork();

   if (pid == -1) {
      printf("Errore creando il processo\n");
      perror("fork");
      exit(EXIT_FAILURE);
   }

   if (pid == 0) {
      n_tot_moltip = n_arg1 * n_arg2;
      printf("Processo figlio %ld - %d * %d = %d\n", (long)getpid(), n_arg1, n_arg2, n_tot_moltip);
      exit(EXIT_SUCCESS);
   } else {
      n_tot_somma = n_arg1 + n_arg2;
      printf("Processo padre %ld - %d + %d = %d\n", (long)getpid(), n_arg1, n_arg2, n_tot_somma);
      exit(EXIT_SUCCESS);
   }

   return(EXIT_SUCCESS);
}
