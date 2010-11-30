#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENTAZIONE DI UN VETTORE DINAMICO CON RIDEFINIZIONE DELL'AMPIEZZA
 *******************************************************************************
 * Realizzazione di un vettore dinamico, l'ampiezza dello stesso sara' decisa a
 * run-time dall'utente, l'utente inoltre dovra' inizializzare ciascun elemento,
 * dopodiche' ciascun elemento sara' stampato in output.
 *
 * Dopo questa prima operazione sara' chiesto all'utente di ridefinire
 * l'ampiezza del vettore stesso, dopodiche' si procedera' alla inizializzazione
 * dei nuovi elementi.
 */

/* Si definisce il tipo di dato con cui lavorare, un intero di tipo int; si
 * realizza inoltre il nuovo tipo di dato con cui gestire la memoria dinamica,
 * un puntatore ad intero nel caso specifico. */
typedef int TipoDato;
typedef TipoDato *DatoVettore;

/* Prototipi di funzione */
void StampaElementi(TipoDato elem[], int size);
void InizializzaElementi(TipoDato *vett, int size, int old_size);

int main(void)
{
	int size;
	int new_size;
	DatoVettore vettore_din;

	printf("Definire l'ampiezza del vettore: ");
	scanf("%d", &size);

	/* Si alloca la memoria corretta, da notare l'utilizzo del tipo di dato che
	 * e' stato scelto all'inizio dell'implementazione; cosi' facendo, qualora
	 * si volesse utilizzare un tipo di dato diverso da int, si potra' gestire
	 * tale operazione direttamente mediante l'istruzione typedef, rendendo il
	 * programma il piu' generale possibile. */
	
	vettore_din = malloc(size * sizeof(TipoDato));

	/* Si riempie il vettore, da notare il passaggio dell'argomento 0, e'
	 * necessario poiche' anche successivamente si utilizzera' questa funzione
	 * per creare un vettore che tuttavia dovra' essere inizializzato con
	 * caratteristiche diverse; serve per determinare quale vettore
	 * inizializzare */

	InizializzaElementi(vettore_din, size, 0);
	StampaElementi(vettore_din, size);

	printf("\nIl vettore attualmente e' composto da %d elementi\n"
			"Di quanto si vuole ampliare il vettore?  ", size);
	scanf("%d", &new_size);

	/* Si ridefinisce l'ampiezza del vettore, utilizzando la realloc() */
	vettore_din = realloc(vettore_din, (size+new_size) * sizeof(TipoDato));

	/* Il terzo argomento passato alla funzione riguarda la vecchia ampiezza del
	 * vettore, necessario affinche' possa interagire correttamente con l'indice
	 * dell'inizializzazione all'interno della funzione */
	InizializzaElementi(vettore_din, size+new_size, size);
	StampaElementi(vettore_din, size+new_size);

	/* Si rilascia la memoria precedentemente allocata */
	free(vettore_din);

	return(EXIT_SUCCESS);
}

/* Stampa tutti gli elementi contenuti nel vettore */
void StampaElementi(TipoDato elem[], int size)
{
	int index;

	for (index=0; index<size; index++)
		printf("vettore[%d]= %10.d\n", index, elem[index]);
}

/* Inizializza ciascun elemento del vettore, verificando se si stratta del
 * vettore iniziale o di quello ridefinito */
void InizializzaElementi(TipoDato *vett, int size, int old_size)
{
	int index;

	printf("Inizializzazione vettore\n");
	
	/* Se old e' uguale a 0 si inizializza il primo vettore dinamico,
	 * altrimenti il secondo vettore ridefinito */
	(old_size == 0) ? (index = 0) : (index = old_size);

	for ( ; index<size; index++) {
		printf("Immettere un intero per il (%2d°) elemento: ", index+1);
		scanf("%d", &vett[index]);
	}

}
