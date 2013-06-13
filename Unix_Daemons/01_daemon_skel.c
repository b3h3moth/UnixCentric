#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <signal.h>

/* I demoni sono processi che godono di una vita media sensibilmente maggiore 
rispetto agli altri processi, solitamente sono eseguiti subito dopo la fase di 
boostrap e chiusi nella fase di shutdown del sistema, una delle caratteristiche
tipiche di un demone e' l'assenza del terminale di controllo, per cui sono 
eseguiti in background. 

I sistemi operativi UNIX, sia BSD sia SystemV, utilizzano specifici demoni per
la gestione di ogni sorta di caratteristica del sistema.*/

void daemonize(const char *cmd);

int main(void) {
    daemonize("demonazzi");

    return(EXIT_SUCCESS);
}

void daemonize(const char *cmd)
{
    int                 i, fd0, fd1, fd2;
    pid_t               pid, sid;
    struct rlimit       rl;
    struct sigaction    sa;

    /* cambia il file mode mask */
    umask(0);

    /* Numero massimo di file descriptors 
    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
       puts("errore");
       exit(-1);
    }
    */

   /* Diventa leader di sessione */
   if ((pid = fork()) < 0) {
      puts("errore fork");
      exit(-1);
   } 
   
   /* Si chiude il parent process */
   if (pid != 0)
      exit(0);
   
   /* Si crea una nuova sessione */
   if ((sid = setsid()) < 0) {
      puts("erreo setsid");
      exit(-1);
   } 

/* Si evita il terminale di controllo  
   sa.sa_handler = SIG_IGN;
   sigemptyset(&sa.sa_mask);
   sa.sa_flags = 0;

   if (sigaction(SIGHUP, &sa, NULL) < 0) {
       puts("sigaction error");
       exit(-1);
   }
   if ((pid = fork()) < 0) {
      puts("errore fork");
         exit(-1);
   } else if (pid != 0)
      exit(0);
*/

   /* Si cambia la directory corrente con l'attuale */
   if (chdir("/") < 0) {
       puts("chdir error");
       exit(-1);
   }
  
/* Si chiudono tutti i fd aperti
   if (rl.rlim_max == RLIM_INFINITY)
       rl.rlim_max = 1024;
   for(i=0; i<rl.rlim_max; i++)
       close(i);
*/

   /* Si attaccano i fd 0,1,2 a /dev/null */
   fd0 = open("/dev/null", O_RDWR);
   fd1 = dup(0);
   fd2 = dup(0);

   /* Si inizializza il file di log */
   openlog(cmd, LOG_CONS, LOG_DAEMON);
   if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
       syslog(LOG_ERR, "fd inaspettato %d %d %d", fd0, fd1, fd2);
       exit(1);
   }

}
