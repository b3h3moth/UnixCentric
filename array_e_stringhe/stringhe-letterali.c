#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
   /* corretto si ma in output  andrebbe anche lo spazio */
   printf("io mi chiamo \
   	 luca suriano \
	 e sono di campobasso");

   /* meglio cosi' */
   printf("\nio mi chiamo \
luca suriano \
e sono di campobasso");

  /* ancor meglio */ 
   printf("\nio mi chiamo"
   	 " luca suriano"
	 " e sono di campobasso\n\n");

   /* Allorquando il compilatore deve allocare spazio per una stringa letterale
    * alloca precisamente la dimensione della stringa n + 1 byte, quel byte
    * aggiuntivo è un carattere null i cui bit sono tutti a zero, ed è il
    * delimitatore della stringa.
    *
    * Il compilatore pertanto tratta la stringa letterale come se fosse un
    * vettore, trattandola come un tipo char *, puntatore a char; quando
    * realizzo una stringa letterale devo ricordare che il puntatore punta alla
    * prima lettera della stringa.
    * es.
    * char *p;
    * p = "ciao";
    *
    * p punta alla prima lettera della stringa "ciao".
    *
    * Possiamo quindi usare una stringa letterale ovunque il C ammetta un
    * puntatore a char.
    */

   char *p;
   p = "abc";
   printf("%s\n", p);
   
   /* poichè i puntatori possono essere indicizzati, possiamo fare altrettando
    * con le stringhe letterali
    */
   char ch;
   ch ="abc"[1]; /* Tecnica non molto utilizzata ma efficace all'uopo, interessante */
   printf("%c\n", ch);

   return(EXIT_SUCCESS);
}
