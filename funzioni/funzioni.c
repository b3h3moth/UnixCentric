#include <stdio.h>
#include <stdlib.h>

/* Prototipi delle funzioni */
double Media(double val_a, double val_b);

int main(int argc, char *argv[])
{
	/* LE FUNZIONI sono essenziali nel contesto di un programma C, poiche'
	 * aiutano notevolmente nella realizzazione di programmi agili e
	 * performanti.
	 *
	 * La tipica funzione C99 e' cosi' strutturata:
	 *
	 * tipo-restituito ID-funzione( parametri )
	 * {
	 *     dichiarazioni
	 *     istruzioni
	 * }
	 *
	 * Il tipo-restituito e' il valore restituito dalla funzione stessa ed e'
	 * caratterizzato da alcune regole ben definite:
	 * - Qualora non dovesse essere prevista la restituzione di un valore, sara'
	 *   specificato il tipo void;
	 * - Le funzioni non prevedono la restituzione di vettori;
	 * - (C89) Se si dovesse omettere il tipo-restituito sara' utilizzato il
	 *   tipo di default <int>, in (C99) non e' prevista tale circostanza.
	 * 
	 * ID-funzione, e' il nome della funzione, c'e' ampia liberta' in tal senso,
	 * tuttavia e' sempre meglio utilizzare nomi autoesplicativi che possano
	 * aiutare coloro che leggeranno il programma.
	 *
	 * Dopo il nome o ID, tra parentesi, ci sono i parametri, ciascun parametro
	 * deve essere preceduto da uno specificatore di tipo, tale regola vale
	 * anche quando ci sono diversi parametri dello stesso tipo; quando la 
	 * funzione comprende diversi parametri ciascuno sara' separato dall'altro
	 * mediante una virgola, se invece la funzione non prevede parametri si puo'
	 * utilizzare void.
	 *
	 * Il corpo di una funzione puo' essere caratterizzato sia da dichiarazioni
	 * sia da istruzioni; le variabili dichiarate all'interno della funzione
	 * hanno lo scope (ambito di visibilita') all'interno della funzione stessa,
	 * per cui non sono visibili all'esterno del blocco della funzione. Nel C89
	 * le variabili dovevano essere dichiarate prima di tutte le altre
	 * istruzioni, nel C99 questa restrizione non c'e', naturalmente una
	 * variabile per essere utilizzata dovra' essere prima dichiarata, questo e'
	 * ovvio.
	 *
	 * Concettualmente appare logico che una funzione dovrebbe essere definita
	 * prima del main per poter essere utilizzata, poiche' altrimenti sarebbe
	 * impossibile ottenere le informazioni necessarie per chiamare la funzione
	 * stessa; nel C99 e' possibile ovviare a questo problema dichiarando il
	 * prototipo della funzione prima che possa essere invocata, tale
	 * dichiarazione fornisce al compilatore i dettagli relativi al tipo di dato
	 * e ai parametri, la definizione della stessa invece potra' essere
	 * implementata successivamente. Tale dichiarazione prende il nome di
	 * prototipo della funzione, e consta della prima linea della definizione,
	 * seguito pero' da un punto e virgola finale:
	 *
	 * tipo-restituito ID-funzione( parametri );
	 *
	 * Ovviamente il prototipo della funzione deve essere fedele alla sua
	 * definizione, nel prototipo inoltre per cio' che concerne i parametri, non
	 * c'e' l'obbligo di inserire il nome ma e' sufficiente il tipo di dato:
	 *
	 * <int Somma(int, int);> piuttosto che <int Somma(int x, int y);>
	 * Questa comunque non e' una regola ma solo una possibilita', che peraltro
	 * andrebbe presa con le molle e comunque gestica con criterio.
	 *
	 */

	double x = 10.8,  y = 89.90;

	printf("la media di %g + %g = %g\n", x, y, Media(x,y));
	
	return(EXIT_SUCCESS);
}

double Media(double val_a, double val_b)
{
	return ( (val_a + val_b) / 2);
}


/* Regole stilistiche e altro:
 * - Inserire il tipo restitioto sopra il nome della funzione migliora la
 *   leggibilita' allorquando dovessero essere utilizzati tipi di dato piuttosto
 *   lunghi, come ad esempio potrebbe esssere <unsigned long int>.
 *
 * - Nella dichiarazione di una funzione e' possibile inserire solo il tipo di
 *   dato, senza il nome della variabile.
 *
 * - Il corpo di una funzione dichiarata void, puo' anche essere vuoto.
 *
 * - Il casting (void) e' un modo educato per dire "butta via"; ci si trova
 *   nel caso in cui si debba scartare una funzione.
 */
