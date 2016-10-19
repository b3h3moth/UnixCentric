## Command-line arguments and main() function

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
