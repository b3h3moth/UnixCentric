#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* fork() */
#include <string.h> /* strerror() */
#include <errno.h> 

int main(int argc, char *argv[]) {
/*
    A ciascun nuovo processo il Sistema Operativo assegna un intero non-negativo
    progressivo, il PID (Process Identifier); si utilizzano le Syscall getpid()
    e getppid() per ottenere il PID del Parent Process e del Child Process, 
    rispettivamente.

    Nei sistemi operativi UNIX una modalita' per creare un nuovo processo e' 
    mediante la SystemCall fork(), che da vita ad un Child Process, copia esatta
    del Parent Process; in realta' la terminologia corretta dovrebbe essere che
    la fork() crea un Child Process del processo chiamante.

    Non appena viene invocata la fork(), il PID del Child Process viene 
    assegnato al Parent Process e il PID del Child Process assume valore zero,
    in pratica il PID del Child Process viene restituito al processo chiamante.

    Il Sistema Operativo assegna due porzioni di memoria private, una per il
    Parent Process, l'altra per il Child Process, pertanto qualora uno dei due
    processi dovesse modificare una *propria* variabile, tale modifica non
    sarebbe visibile ad entrambi; i file aperti invece sono condivisi, per cui 
    una eventuale modifica ad un file sarebbe ad entrambi visibile.

    I concetti pocanzi espressi possono essere sintetizzati come segue:
    - Il Child Process e' una copia del data segment, dello stack e dello heap
    del Parent Process, tale copia e' ad uso e consumo del Child Process e 
    pertanto non vi e' condivisione col Parent Process;
    - La sezione text segment e' condivisa tra Parent Process e Child Process.
    
    L'implementazione della SystemCall fork() puo' essere diversa a seconda del
    sistema UNIX utilizzato; l'header da utilizzare e' <unistd.h>.

    pid_t e' un tipo di dato definito in sys/types.h, sarebbe stato lo stesso
    se si fosse utilizzato un int. 
*/
   
   pid_t pid = fork();

   if (pid < 0)
      fprintf(stderr, "Err. Process %s\n", strerror(errno));
   else if(pid > 0)
      printf("Sezione relativa al Parent Process\n");
   else
      printf("Sezione relativa al Child Process\n");

   return(EXIT_SUCCESS);
}
