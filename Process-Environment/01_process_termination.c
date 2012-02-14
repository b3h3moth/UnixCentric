#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*
Un processo termina normalmente quando:
1 - Ritorna dal main;
2 - Chiamata ad exit();
3 - Chiamata ad _exit() oppure all'equivalente _Exit();
4 - Mediante thread.

Un processo termina in maniera anomala:
6 - Chiamata ad abort();
7 - Ricezione segnali;
8 - Mediante thread;

La funzione _exit() o _Exit() restituisce immediatamente il controllo al kernel,
la funzione exit() invece esegue prima talune operazioni di pulizia, come ad
esempio la chiusura di tutti gli stream, dopodiche' anch'essa restituisce il 
controllo al kernel chiamando la funzione _exit().

L'argomento di ciascuna funzione indica lo "stato di uscita" del processo,
solitamente 0 corrisponde a true, 1 a false; la shell prevede il comando echo $?
che stampa sullo standard output lo stato di uscita dell'ultimo processo 
eseguito.

Nota: La funzione main() e' una sorta di chiave di accensione per ciascun 
programma, senza di essa infatti non ci sarebbe esecuzione; una routine di avvio
e' chiamata poco prima della funzione main, il cui indirizzo e' il punto di 
partenza dell'eseguibile. Nella funzione main() le funzioni exit(0) e return(0) 
sono del tutto equivalenti.

Talvolta e' estremamente comodo ma anche necessario eseguire diverse operazioni
di pulizia prima della chiusura di un programma, ed e' ancor meglio se tali
operazioni fosse il programmatore stesso a gestirle; la funzione atexit() ad
esempio e' davvero utile in tal senso.

HEADER    : <stdlib.h>
PROTOTYPE : int atexit(void (*func)(void);
SEMANTICS : Registra la funzione 'func' da eseguire all'uscita del programma
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
Nota: L'argomento richiede l'indirizzo di una funzione, senza argomenti e senza
valore di ritorno, del tipo void func(void);

La funzione atexit() consente la registrazione di una funzione di pulizia da
usarsi all'uscita del programma; nella sequenza di chiusura tutte le 
informazioni registrate saranno chiamate in ordine inverso rispetto alla 
registrazione.
*/

static void my_exit_func_1(void);
static void my_exit_func_2(void);
static void my_exit_func_3(void);

int main(int argc, char *argv[]) {

   if (atexit(my_exit_func_1) != 0) {
      fprintf(stderr, "Err: exit 1\n");
      exit(EXIT_FAILURE);
   }
   
   if (atexit(my_exit_func_2) != 0) {
      fprintf(stderr, "Err: exit 2\n");
      exit(EXIT_FAILURE);
   }

   if (atexit(my_exit_func_3) != 0) {
      fprintf(stderr, "Err: exit 3\n");
      exit(EXIT_FAILURE);
   }

   printf("La funzione e' conclusa\nDa notare le chiamate in ordine inverso\n");

   return(EXIT_SUCCESS);
}

static void my_exit_func_1(void)
{
   printf("my_exit_func_1\n");
}

static void my_exit_func_2(void)
{
   printf("my_exit_func_2\n");
}


static void my_exit_func_3(void)
{
   printf("my_exit_func_3\n");
}
