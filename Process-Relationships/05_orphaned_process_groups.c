#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

/*
Un intero gruppo di processi puo' essere reso orfano, ossia puo' perdere il
padre dal quale e' stato generato.
*/

static void signal_handler_sighup(int sig_num);
static void print_process_info(char *process_name);

int main(int argc, char *argv[]) {
    char c;
    pid_t pid;
    
    print_process_info("Padre");
    
    if ((pid = fork()) < 0) {
    	fprintf(stderr,"Err.(%s) fork() failed\n", strerror(errno));
	exit(EXIT_FAILURE);
    } else if (pid > 0) {	
    	/* Processo padre 
	si mette in attesa per 5 secondi dando modo al figlio di fermarsi,
	dopodiche' esce. */
    	sleep(5);
	exit(0);
    } else {
    	/* Processo figlio */
    	print_process_info("Figlio");
	/* cattura il segnale SIGHUP mediante il gestore dei segnali, dopodiche'
	grazie al segnale SIGTSTP il processo figlio si ferma */
	signal(SIGHUP, signal_handler_sighup);
	kill(getpid(), SIGTSTP);
	
	/* stampa solo quando e' ritornato, il ppid ora dovrebbe essere 1, ossia
	adottato da init */
	print_process_info("child");	
	
	if (read(STDIN_FILENO, &c, 1) < 0)
	    fprintf(stderr, "Err.(%s) read() TTY failed\n", strerror(errno));
	exit(0);
    }
    
    return(EXIT_SUCCESS);
}

static void signal_handler_sighup(int sig_num)
{
    printf("Ricevuto il segnale (SIGHUP) - pid: %d\n", getpid());
}

static void print_process_info(char *process_name)
{
    printf("%s - pid: %d, ppid: %d, pgrp: %d, tpgrp: %d\n",\
    	    process_name, getpid(), getppid(), getpgrp(), \
	    tcgetpgrp(STDIN_FILENO));
    
    fflush(stdout);
}

