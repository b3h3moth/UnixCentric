#include <stdio.h>
#include <stdlib.h>

/*
Ogni programma puo' ricevere argomenti ed opzioni, per cio' che concerne gli
argomenti essi possono essere passati all'avvio del programma agli argomenti
della funzione main, che solitamente sono definiti come 'argc' e 'argv', il
primo e' un intero ed indica il numero di argomenti, il secondo e' un puntatore
ad un vettore di stringhe (ogni argomento corrisponde ad una stringa).

Note:
- argv[0] corrisponde sempre, ovviamente, al programma in esecuzione;
- argv[argc] e' sempre un puntatore nullo (argv e' un vettore per cui inizia il
  conteggio da 0, argc invece inizia da 1);
- argc e argv sono nomi convenzionali, si consiglia di non modificarli.
*/


int main(int argc, char* argv[]) {
   int i;
   
   printf("Nome del programma: %s\n", argv[0]);
   printf("E' stato invocato con %d elementi\n", argc);
   
   if (argc > 1) {
      printf("Gli argomenti sono: \n");
      for (i=0; i<argc; ++i)
      	 printf("argv[%i] %s\n", i, argv[i]);
   }

    return(EXIT_SUCCESS);
}
