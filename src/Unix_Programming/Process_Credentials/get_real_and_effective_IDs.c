#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/* Lo scopo del programma e' di stampare le credenziali di un processo, nello
specifico, oltre al PID e PPID, i 'Real' e 'Effective' ID. */

int main(void) {

   printf("                  Process-ID (PID): %d\n", getpid());
   printf("          Parent Process-ID (PPID): %d - shell\n", getppid());

   printf("           Real User-ID (real-UID): %d\n", getuid());
   printf(" Effective User-ID (effective-UID): %d\n", geteuid());
   printf("          Real Group-ID (real-GID): %d\n", getgid());
   printf("Effective Group-ID (effective-GID): %d\n", getegid());

   return(EXIT_SUCCESS);
}
