#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
I segnali rappresentano la modalita' piu' elementare di comunicazione tra
processi, essi sono infatti "software interrupts" - interruzioni software - e
consentono la gestione di eventi asincroni; i segnali sono standard POSIX.1.

Tutti i segnali, definiti nell'header <signal.h>[1], hanno un nome specifico, le
prime tre lettere tuttavia sono identiche per ciascuno di essi, ovvero SIG; 
ogni nome definisce una costante il cui valore indica un intero positivo, il
"signal number" - numero del segnale.

Nota: Non vi e' un "signal number" 0, POSIX.1 lo definisce in questo ambito come
      "null signal" - segnale nullo.

I segnali sostanzialmente sono utilizzati affinche' si possa comunicare ad un
processo il verificarsi di un particolare evento, ma quali sono le modalita' per
le quali si possa generare un segnale? Alcune di esse sono:

- Un segnale puo' essere generato dall'utente allorquando invia dalla tastiera
  una particolare combinazione di tasti per terminare o sospendere il programma,
  come ad esempio Control-Z oppure Control-C;
 
- Un segnale puo' essere generato a causa di eccezioni hardware, come ad esempio
  una divisione per zero o un riferimento non valido alla memoria; tali 
  condizioni generalmente sono rilevate dall'hardware e notificate al kernel, il
  quale provvede ad inviare un segnale al processo in esecuzione nel momento in
  cui si e' verificata l'eccezione;

- La funzione kill - man 2 kill - permette ad un processo di inviare un 
  qualunque tipo di segnale ad un altro processo oppure ad un "process group",
  tuttavia per farlo e' necessario essere o il proprietario del processo al
  quale si sta inviando un segnale o essere il superuser (root, amministratore);

- Il comando kill - man 1 kill - consente di inviare un segnale ad un altro
  processo. Tale comando altro non e' che una interfaccia della funzione kill();
 
- Vi sono inoltre delle condizioni non causate dall'hardware ma dal software, 
  come ad esempio la scadenza di un timer o di un allarme o una operazione
  di I/O non ammessa, e cosi' via.

I segnali, come accennato pocanzi, sono eventi asincroni, pertanto possono 
capitare in qualsiasi momento e di certo non possono essere gestiti con la 
semplice definizione di una variabile, ma piuttosto vi deve essere un meccanismo
che consenta ad un processo di comunicare con il kernel su come (re)agire al 
verificarsi di un segnale.

Da notare che gli eventi inseriti pocanzi comportano sempre l'intervento del 
kernel, e' il kernel stesso che genera il segnale, che al verificarsi dell'
evento puo':

1 - Ignorare il segnale.
    I segnali SIGKILL e SIGSTOP non possono essere ignorati, cosi' come quelli
    generati da eccezioni hardware;

2 - Catturare il segnale,
    Al verificarsi del segnale e' necessario informare il kernel di invocare
    una funzione creata ad-hoc; i segnali SIGKILL e SIGSTOP non possono essere
    catturati.

3 - Comportamento di default.
    Ciascun processo ha un comportamento di default, che nella maggior parte dei
    casi corrisponde alla terminazione del processo.

Unix System Signals:




HEADER    : 
PROTOTYPE : 
SEMANTICS : 
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
/*
[1] In realta' le diverse implementazioni dei sistemi unix-like definiscono i
    segnali in altri header, tuttavia e' considereata buona pratica inserire
    solo l'header citato.
