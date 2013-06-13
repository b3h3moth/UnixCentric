#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/* I demoni sono processi che godono di una vita media sensibilmente maggiore 
rispetto agli altri processi, solitamente sono eseguiti subito dopo la fase di 
boostrap del sistema e terminati nella fase di shutdown del sistema stesso; una
tra le caratteristiche tipiche di un demone e' l'assenza del terminale di 
controllo, per cui e' eseguito in background e senza interazione con l'utente.

Nota: Un demone in esecuzione puo' essere riconosciuto, talvolta, dal carattere
      finale 'd', ad esempio tipici demoni sono sshd, acpid, rsyslogd, httpd, ma
      anche cron, portmap, etc. Il comando 'ps axj' puo' essere utile in tal 
      senso.

I sistemi operativi UNIX utilizzano specifici demoni per la gestione di ogni 
sorta di caratteristica del sistema e sono scritti seguendo regole ben 
definite:

- Creazione di un processo e chiusura del padre (fork);
- Settaggio della maschera di creazione dei permessi dei file (umask);
- Creazione di una nuova sessione per il processo figlio (setsid);
- Cambiamento della working directory (chdir);
- Chiusura di tutti i file descriptor;
- Gestione del log (syslog);

*/

void daemonize(void);

int main(void) {
    daemonize();

    return(EXIT_SUCCESS);
}

void daemonize(void)
{
    pid_t pid, sid;

    /* Si provvede ad una verifica iniziale, ovvero se la funzione getppid()
    restituira' 1 vorra' dire che il PPID del programma in esecuzione sara'
    init con PID 1 per l'appunto, e quindi si potra' proseguire tranquillamente,
    questo perche' ciascun demone ha come genitore proprio init. E' una sorta
    di verifica iniziale. */
    
    if (getppid() == 1) {
        puts("init");
        return;
    } else
        puts("ahi ahi ani");

    /* E' necessario creare un nuovo processo, il padre tuttavia sara' subito 
    terminato in modo tale da lasciare in esecuzione solo e soltanto il processo
    figlio. */

    if ((pid = fork()) < 0)
        exit(EXIT_FAILURE);

    if (pid > 0) 
        exit(EXIT_SUCCESS);

    /* A questo punto del programma dovrebbe essere in esecuzione solo il 
    processo figlio, cosi come si prevede bei demoni. */

    /* Quando un utente crea un file o una directory, essi sono settati con i
    permessi di default, tali permessi tuttavia possono essere modificati 
    mediante la maschera di creazione dei permessi dei file.
    
    Per cio' che concerne un demone e' assolutamente necessario poter leggere
    e scrivere sui file, per cui impostando il valore di umask a 0 si avra' 
    l'accesso completo alle risorse da parte del demone. */
    
    umask(0);

    /* Il processo figlio, unico processo in esecuzione, deve ottenere un SID
    (Session ID o ID di sessione) dal kernel per poter continuare l'esecuzione
    come demone; si invoca la funzione setsid() che consente la creazione di una
    nuova sessione e il processo chiamante, in questo caso il processo figlio,
    diventera' leader della nuova sessione. */

    if ((sid = setsid()) < 0) {
        fprintf(stderr, "Err. %d setsid() %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Numero massimo di file descriptors 
    if (getrlimit(RLIMIT_NOFILE, &rl) < 0) {
       puts("errore");
       exit(-1);
    }
    */

   /* Diventa leader di sessione */
   /* Si crea una nuova sessione
   if ((sid = setsid()) < 0) {
      puts("erreo setsid");
      exit(-1);
   } 
   */

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

   /* Si cambia la directory corrente con l'attuale
   if (chdir("/") < 0) {
       puts("chdir error");
       exit(-1);
   }
   */
  
/* Si chiudono tutti i fd aperti
   if (rl.rlim_max == RLIM_INFINITY)
       rl.rlim_max = 1024;
   for(i=0; i<rl.rlim_max; i++)
       close(i);
*/

   /* Si attaccano i fd 0,1,2 a /dev/null
   fd0 = open("/dev/null", O_RDWR);
   fd1 = dup(0);
   fd2 = dup(0);
   */

   /* Si inizializza il file di log
   openlog(cmd, LOG_CONS, LOG_DAEMON);
   if (fd0 != 0 || fd1 != 1 || fd2 != 2) {
       syslog(LOG_ERR, "fd inaspettato %d %d %d", fd0, fd1, fd2);
       exit(1);
   }
   */

}
