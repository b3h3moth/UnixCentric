#include <stdio.h>
#include <stdlib.h>

/*
 * Per allocare dinamicamente la memoria è necessario inserire l'header
 * <stdlib.h> che contiene le funzioni:
 *
 * - malloc, alloca un blocco di memoria senza inizializzarlo;
 * - calloc, alloca un blocco di memoria azzerandolo;
 * - realloc, ridimensiona un blocco di memoria precedentementa allocato.
 *
 * Quando si alloca la memoria, e la funzione porta a termine il proprio dovere,
 * ovvero allocando la memoria richiesta, la funzione stessa nestituirà un
 * puntatore a void <void *> questo perchè naturalmente non si sa con quale tipo
 * di dato si andrà a lavorare.
 */

/*
 * PUNTATORE NULLO
 * Allorquando una funziona per l'allocazione della memoria viene chiamata, vi è
 * sempre la possibilità che questa non sia in grado di allocare un blocco di
 * memotia sufficientemente grande da soddisfare la richiesta; in tal caso la
 * funzione restituirebbe un puntatore nullo.
 *
 * Il puntatore nullo è la macro NULL.
 */

int main(int argc, char *argv[])
{
   /*
    * Si puo controllare il valore restituito dalla <malloc>:
    */
   int *p, *p2; /* Si è utilizzato un puntatore ad intero ma si sarebbe potuto 
   	      adoperare qualsiasi dato */

   p = malloc(1000);

   if (p == NULL) {
      ;/* Allocazione fallita */
   }

   /* 
    * Anche combinare insieme il tutto
    */

   if ((p2 = malloc(1000)) == NULL) {
      ;/* Allocazione fallita */
   }


   return(EXIT_SUCCESS);
}
