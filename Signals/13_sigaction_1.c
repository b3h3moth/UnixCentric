#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

/*
La funzione sigaction() consente di esaminare e/o modificare l'azione associata
ad uno specifico segnale; lo standard POSIX consiglia di utilizzare questa 
funzione piuttosto che la obsoleta signal().

HEADER    : <signal.h>
PROTOTYPE : int sigaction(int signo, const struct sigaction act, 
            struct sigaction old_act);
SEMANTICS : La funzione sigaction() installa una nuova azione relativa al
            segnale indicato in 'signo'.
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
- Il parametro 'signo' indica il segnale da modificare; 
- se il puntatore 'act' non e' nullo, si modifica l'azione installando la 
  funzione specificata; 
- se il  puntatore 'old_act' non e' nullo viene restituito il valore dell'azione
  corrente.

Nota: Si e' gia' superato un limite della signal(), ovvero la restituzione 
      dell'azione corrente senza dover installarne una nuova, nel caso in cui
      'act' dovesse essere un valore nullo e 'old_act' un valore non-nullo.
      In pratica il parametro 'old_act' consente di recuperare lo stato del 
      gestore originale nel momento in cui si installa quello nuovo.

Struttura sigaction
-------------------
I puntatori del secondo e terzo parametro fanno riferimento alla struttura 
'sigaction', che specifica le caratteristiche dell'azione associata al segnale:

struct sigaction {
	void (*sa_handler)(int);
	sigset_t sa_mask;	
	int sa_flags;	
	void (*sa_sigaction)(int, siginfo_t *, void *);
	void (*sa_restorer);
};

Nota: ll campo 'sa_restorer' non fa parte dello standard POSIX e pertanto non 
deve essere considerato.

- sa_mask , indica l'insieme dei segnali bloccati durante l'elaborazione del
            gestore, ad essi viene aggiunto anche il segnale che ne ha causato
	    la chiamata, se non specificato altrimenti con 'sa_flags'.

- sa_flags, consente di impostare diversi valori, flag per l'appunto, che 
            possono modificare il processo di gestione dei segnali:
	    - SA_INTERRUPT
	    - SA_NOCLDSTOP
	    - SA_NOCLDWAIT
	    - SA_NODEFER
	    - SA_ONSTACK
	    - SA_RESETHAND
	    - SA_RESTART
	    - SA_SIGINFO, se si vuole utilizzare un signal-handler in forma
	                  estesa mediante 'sa_sigaction' invece di 'sa_handler'

Struttura siginfo_t
-------------------
E' possibile utilizzare due tipi di signal-handler, uno mediante sa_sigaction,
l'altro mediante sa_handler, il primo e' molto piu' complesso poiche' consente
di ottenere diverse informazioni aggiuntive grazie alla struttura siginfo_t.

Nota: La funzione signal() utilizza sa_handler.

*/

int main(int argc, char *argv[]) {

    return(EXIT_SUCCESS);
}
