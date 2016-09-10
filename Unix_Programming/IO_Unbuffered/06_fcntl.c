#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/*
HEADER   : <fcntl.h>
PROTOTYPE: int fcntl(int fd, int cmd, ... < arg > );
La funzione fcntl() e' una sorta di punto di accesso per l'esecuzione di 
diverse operazioni sul file descriptor. Il primo argomento 'fd' e' un file
descriptor aperto, il secondo argomento 'cmd' indica il tipo di operazione da
eseguire, il terzo argomento 'arg' e' opzionale, se utilizzarlo o meno e' 
determinato da 'cmd'.
I valori di ritorno sono diversi a seconda dell'operazione eseguita, in caso di
errore ritorna sempre -1.

La funzione fcntl() puo' modificare le proprieta' di un file descriptor, 
tuttavia il numero degli argomenti, il valore di ritorno, errori compresi, 
sono strettamente legati al valore della variabile intera 'cmd', che puo' 
assumere i seguenti valori:

F_DUPFD, duplica il file descriptor;
F_GETFD, ritorna il valore del file descriptor flag;
F_SETFD, setta il valore del file descpritor flag;
F_GETFL, ritorna il valore del file status flag;
F_SETFL, setta il valore del file status flag;
F_GETLK, ritorna informazioni sul record locking;
F_SETLK, setta informazioni sul record locking;
F_SETLKW, come sopra, non ritorna subito ma attende il rilascio del blocco;
F_GETOWN, ritorna il PID o il PGID, preposto alla ricezione dei segnali SIGURS;
F_SETOWN, setta il PID o il PGID, preposto alla ricezione dei segnali SIGURS;
F_GETSIG, ritorna il segnale inviato quando l'input o l'output e' disponibile;
F_SETSIG, setta il segnale inviato quando l'input o l'output e' disponibile;
F_SETLEASE, imposta o rimuove un file lease; 
F_GETLEASE, setta un file lease;
F_NOTIFY, attiva un meccanismo di notifica.

Tra le operazioni piu' comuni vi e' la possibilita' di mettere un blocco in
lettura o in scrittura ad un file; il blocco in lettura e' posto su un
descrittore di file leggibile, mentre il blocco in scrittura su uno
scrivibile. */

int main(int argc, char *argv[]) {
    int val;
    
    if (argc < 2) {
    	fprintf(stderr, "Usage: %s <N file descriptor>\n", argv[0]);
	    /* es: ./a.out 0 < /etc/fstab */
	    exit(EXIT_FAILURE);
    }

    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
    	fprintf(stderr, "Err.(%s) fcntl() failed\n", strerror(errno));
	    exit(EXIT_FAILURE);
    }

    switch (val & O_ACCMODE) {
    	case O_RDONLY:
	    printf("read only");
	    break;

	case O_WRONLY:
	    printf("write only");
	    break;

	case O_RDWR:
	    printf("read write");
	    break;

	default:
	    printf("access mode unknow");
	    exit(EXIT_FAILURE);
    }

    if (val & O_APPEND)
    	printf(", append");

    if (val & O_NONBLOCK)
    	printf(", non-blocking");

#if defined(O_SYNC)
    if (val & O_SYNC)
    	printf(", async writing");
#endif
    printf("\n");

    return(EXIT_SUCCESS);
}
