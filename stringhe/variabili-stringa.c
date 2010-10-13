#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
   /* Il C tratta le variabili stringa come vettore unidimensionali con
    * l'aggiunta di un terminatore di stringa.
    *
    * Allorquando si crea una variabile che dovessere servire come stringa
    * bisogna sempre calcolare anche il carattere in più.
    * es.
    * #define STR_LEN 80
    * char str[STR_LEN + 1];
    *
    * Questa pratica è comunissima tra i programmatori C
    * 
    * INIZIALIZZAZIONE:
    * Una variabile stringa puà essere inizializzata nel momen to della
    * dichiarazione
    */
   char date[8] = "June 14"; /* sembra una stringa letterale ma non lo è, 
   				il C la vede come un'abbreviazione 
				dell'inizializzazione di un  vettore */


   /* Si può omettere la lunghezza, che sarà calcolata dal compilatore
    */
   char date2[] ="March 31";
   printf("date %d\ndate2 %d\n", strlen(date), strlen(date2));

   /* VETTORI DI CARATTERI E PUNTATORI A CONFRONTO 
    * char date [] = "June 14";
    * char *date2 = "June 14;
    *
    * Il primo tratta date come un vettore, il secondo tratta date2 come un
    * puntatore, pertanto in qualsiasi funzione le potremmo utilizzare entrambe,
    * tuttavia questo non vuol dire che siano intercambiabili.
    *
    * Nella prima versione ogni carattere può essere modificato come in un
    * vettore, perchè è un vettore; nel secondo caso si tratta di una stringa
    * letterale, pertantoi caratteri non possono essere modificati.
    *
    * Nella prima date è un vettore, dichiarato come vettore; nella seconda
    * date2 è un puntatore pertanto nel corso del programma può esser fatto
    * puntare verso ad altri lidi :)
    *
    * char *p;
    * dichiara un puntatore a char, certo può essere una stringa ma il
    * compilatore alloca lo spazio per contenere un puntatore a char e non per
    * una stringa, e del resto come potrebbe?
    *
    * Una possibilità però è di farla puntare ad una stringa
    * char str[STR_NEL+1], *p;
    * p = str;
    * Oppure ad una stringa allocata dinamicamente.
    */


   return(EXIT_SUCCESS);
}
