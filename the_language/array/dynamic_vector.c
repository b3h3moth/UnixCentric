#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENTAZIONE DI UN VETTORE DINAMICO
 *******************************************************************************
 * Realizzazione di un vettore dinamico, l'ampiezza dello stesso sara' decisa a
 * run-time dall'utente, l'utente inoltre dovra' inizializzare ciascun elemento,
 * dopodiche' ciascun elemento sara' stampato in output.
 */

/* Si definisce il tipo di dato con cui lavorare, un intero di tipo int, si
 * realizza inoltre il nuovo tipo di dato con cui gestire la memoria dinamica,
 * un puntatore ad intero nel caso specifico. */
typedef int TipoDato;
typedef TipoDato *DatoVettore;

int main(int argc, char *argv[])
{
	int size, i;
	DatoVettore vettore_dinamico;

	printf("Definire l'ampiezza del vettore: ");
	scanf("%d", &size);

	/* Si alloca la memoria corretta, da notare l'utilizzo del tipo di dato che
	 * e' stato scelto all'inizio dell'implementazione; cosi' facendo, qualora
	 * si volesse utilizzare un tipo di dato diverso da int, si potra' gestire
	 * tale operazione direttamente mediante l'istruzione typedef, rendendo il
	 * programma il piu' generale possibile. */
	vettore_dinamico = malloc(size * sizeof(TipoDato));

	/* Si riempie il vettore */
	printf("Inizializzazione vettore\n");
	for (i=0; i<size; i++) {
		printf("Immettere un intero per il (%d°) elemento: ", i+1);
		scanf("%d", &vettore_dinamico[i]);
	}

	for (i=0; i<size; i++)
		printf("vettore[%d]= %d\n", i, vettore_dinamico[i]);

	/* Si rilascia la memoria precedentemente allocata */
	free(vettore_dinamico);

	return(EXIT_SUCCESS);
}
