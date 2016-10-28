# Process Environment

* [Command-line arguments and main() function](#headPE0)
* [Nonlocal goto with setjmp() and longjmp()](#headPE1)

---

## <a name="headPE0">Command-line arguments and main() function</a>

La funzione `main()`, come accennato nel sorgente dedicato alla terminazione dei
processi, e' una funzione essenziale, dal punto di vista dello sviluppatore 
ad esempio e' possibile accedere alle informazioni passate dall'utente 
attraverso i parametri `int argc` e `char *argv[]` della funzione `main()`
stessa.

> Nota: `argc` e' un intero ed indica il numero di argomenti, `*argv[]` invece 
> e' un puntatore ad un vettore di stringhe, ossia ognuno degli elementi che lo 
> costituiscono referenzia una stringa contenente uno dei parametri passati 
> dalla shell.

- `argv[0]` corrisponde sempre, ovviamente, al programma in esecuzione;
- `argv[argc-1]` referenzia l'ultimo parametro;
- `argv[argc]` e' sempre un puntatore NULL, che indica la fine del vettore;
- `argc` e `argv` sono nomi convenzionali, si consiglia di non modificarli.

## <a name="headPE1">Nonlocal goto with setjmp() and longjmp()</a>

Di norma una funzione ritorna nel punto dall quale e' stata invocata, con la
funzione ``setjmp()`` invece e' possibile far saltare una funzione in un'altra 
senza che si effettui un return.

L'header ``<setjmp.h>`` mette a disposizione due funzioni, l'una in stretta
correlazione con l'altra, esse sono per l'appunto ``setjmp()`` e ``longjmp()``, 
con le seguenti caratteristiche

``int setjmp(jmp_buf env);``

La funzione ``setjmp()`` salva lo stack, contesto/ambiente corrente, nella 
variabile ``env``, per essere utilizzata successivamente da ``longjmp()``.
Ritorna 0 se chiamata direttamente, non zero se ritorna da ``longjmp()``.

``void longjmp(jmp_buf env, int val);``

La funzione ``longjmp()`` ripristina l'ambiente salvato dall'ultima chiamata a 
``setjmp()`` mediante la variabile ``env'``; dopo aveer completato l'esecuzione 
restituisce il controllo a ``setjmp()``, restituendo ``val``.

La funzione ``setjmp()`` fissa una posizione all'interno del programma, salvando
l'ambiente corrente nella variabile ``env`` di tipo ``jmp_buf`` e ritornando 
``0``, la funzione ``longjmp()`` invece puo' essere adoperata per tornare nella 
posizione definita da ``setjmp()``; l'uso delle funzioni su citate tuttavia 
riguarda soprattutto la gestione degli errori e degli interrupts.

In breve:
- ``setjmp()`` ritorna ``0`` alla prima invocazione;
- ``longjmp()`` trasferisce nuovamente il controllo alla chiamata originaria 
  ``setjmp()``, restituendo zero.
