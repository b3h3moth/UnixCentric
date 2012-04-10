#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
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

I puntatori del secondo e terzo parametro fanno riferimento alla struttura 
'sigaction':

struct sigaction {
	void (*sa_handler)(int);	indirizzo del segnale
	sigset_t sa_mask;		segnali addizionali da bloccare
	int sa_flags;			opzioni
	...
};



*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
