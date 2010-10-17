/* Programma che genera un processo figlio e che poi termina prima del figlio
 * stesso, rendendolo orfano; attenzione, non si sta parlando di zombie, lo
 * scopo e' di far adottare l'orfano da init
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define AUTHOR		"Luca Suriano"
#define MAIL_AUTHOR	"luka@linux.it"

void son_process(void);
void parent_process(pid_t pid);

int main(int argc, char *argv[])
{
   pid_t son_pid;

   printf("PID = %ld - Parent PID = %ld\n", (long)getpid(), (long)getppid() );

   son_pid = fork(); 

   if (son_pid == -1) {
      perror("fork");
      exit(13);
   }

   if (son_pid == 0)
      son_process();
   else
      parent_process(son_pid);

   return(EXIT_SUCCESS);
}

void son_process(void)
{
   sleep(10);
   printf("Questo è il processo figlio\n");

   if (getppid() == 1)
      printf("Ho perso il padre\n");

   printf("PID = %ld - Parent PID = %ld\n", getpid(), getppid());
   
}

void parent_process(pid_t pid)
{
   printf("Questo è il processo genitore\n");
   printf("Son PID = %ld - PID %d - Parent PID = %ld\n", pid, getpid(), getppid());

}
