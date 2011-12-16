#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void daemon_body();
int init_daemon();

int main(int argc, char *argv[]) {
   int status;
   status = init_daemon();

   if (status == 0) {
      exit(0);
   } else {
      exit(1);
   }

   return(EXIT_SUCCESS);
}

int init_daemon() {
   pid_t pid;

   if ((pid = fork()) < 0) {
      printf("Installing daemon... FAILED.\n");
      return(-1);
   } else if (pid != 0) {
      printf("Installing daemon... OK.\n");
      return(0);
   }

   setsid();

   /* diventa owner della sessione */
   daemon_body();
   return(1);
}

void daemon_body() {
   time_t t;
   char *st;
   while(1) {
      sleep(10);
      st = (char*)ctime(&t);
      printf("\n Current time: %s ", st);
   }
}
