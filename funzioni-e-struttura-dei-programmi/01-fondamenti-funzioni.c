#include <stdio.h>
#include <stdlib.h>


/* Prototipi delle funzioni */
double Media(double val_a, double val_b);
int Potenza(int x, int n);


int main(int argc, char *argv[])
{
	double x = 10.8,  y = 89.90;
	int val = 2, n = 5;

	/* CONCETTI FONDAMENTALI SULLE FUNZIONI
	 ***************************************************************************
	 * Le funzioni sono essenziali nel contesto di un programma C, poiche'
	 * aiutano notevolmente nella realizzazione di programmi agili e
	 * performanti.
	 *
	 * La tipica funzione C99 e' cosi' strutturata:
	 *
	 * tipo-restituito nome-funzione( parametri )
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
	 * nome-funzione, e' il nome della funzione, c'e' ampia liberta' in tal 
	 * senso, tuttavia e' sempre meglio utilizzare nomi autoesplicativi che
	 * possano aiutare coloro che leggeranno il programma.
	 *
	 * Dopo il nome o ID, tra parentesi, ci sono i parametri, ciascun parametro
	 * deve essere preceduto da uno specificatore di tipo, tale regola vale
	 * anche quando ci sono diversi parametri dello stesso tipo; quando la 
	 * funzione comprende diversi parametri ciascuno di essi deve essere
	 * separato dall'altro mediante una virgola, se invece la funzione non
	 * prevede parametri si puo' utilizzare void.
	 *
	 * Il corpo di una funzione puo' essere caratterizzato sia da dichiarazioni
	 * sia da istruzioni; le variabili dichiarate all'interno della funzione
	 * hanno lo scope (ambito di visibilita') all'interno della funzione stessa,
	 * per cui non sono visibili all'esterno del blocco della funzione. Nel C89
	 * le variabili dovevano essere dichiarate prima di tutte le altre
	 * istruzioni, nel C99 questa restrizione non c'e', naturalmente una
	 * variabile per essere utilizzata deve essere prima dichiarata, questo e'
	 * ovvio.
	 *
	 * Concettualmente appare logico che una funzione dovrebbe essere definita
	 * prima del main per poter essere utilizzata, poiche' altrimenti sarebbe
	 * impossibile ottenere le informazioni necessarie per invocare la funzione
	 * stessa; nel C99 e' possibile ovviare a questo problema dichiarando il
	 * prototipo della funzione prima che possa essere invocata, tale
	 * dichiarazione fornisce al compilatore i dettagli relativi al tipo di dato
	 * e ai parametri, la definizione della stessa invece potra' essere
	 * implementata successivamente. Tale dichiarazione prende il nome di
	 * prototipo della funzione, e consta della prima linea della definizione,
	 * seguito pero' da un punto e virgola finale:
	 *
	 * tipo-restituito nome-funzione( parametri );
	 *
	 * Il prototipo della funzione naturalmente deve essere fedele alla sua
	 * definizione, nel prototipo inoltre, per cio' che concerne i parametri,
	 * non c'e' l'obbligo di inserire il nome ma e' sufficiente il tipo di dato:
	 *
	 * <int Somma(int, int);> piuttosto che <int Somma(int x, int y);>
	 * Questa comunque non e' una regola ma solo una possibilita', che peraltro
	 * andrebbe presa con le molle e comunque gestica con criterio.
	 */

	/* L'esempio seguente mostra in estrema sintesi tutto cio' che e' stato
	 * detto sin'ora. */

	printf("La media di %g + %g = %g\n", x, y, Media(x,y));

	/* ARGOMENTI (ARGOMENTI ATTUALI) E PARAMETRI (ARGOMENTI FORMALI)
	 ***************************************************************************
	 * In genere si indica come parametro (argomento formale) la variabile 
	 * menzionata nell'elenco tra parentesi della definizione  di una funzione,
	 * mentre con argomento (argomento attuale) si indica il valore usato da una
	 * chiamata di una funzione; nel caso specifico, nella chiamata Media(x,y)
	 * le variabili x e y sono argomenti o argomenti attuali, mentre val_a e 
	 * val_b sono parametri o argomenti formali. Gli argomenti attuali pertanto
	 * sono delle espressioni, i parametri sono dei nomi che saranno forniti
	 * alla funzione allorquando sara' invocata.
	 *
	 * Nel C gli argomenti sono passati per valore, cio' vuol dire che quando si
	 * verifica una chiamata di funzione ogni argomento sara' calcolato e il
	 * risultato inserito nel corrispondente parametro.
	 *
	 * Come si evince dalla funzione si lavora con delle copie, pertanto i
	 * valori passati come argomenti non saranno modificati.
	 */

	printf("La potenza di %d^%d = %d\n", val, n, Potenza(val, n));
	printf("Valori degli argomenti nel main val=%d n=%d\n", val, n );

	return(EXIT_SUCCESS);
}


double Media(double val_a, double val_b)
{
	return ( (val_a + val_b) / 2);
}


/* In questo caso la variabile n assumera' il valore -1 all'interno della
 * funzione, ma il corrispettivo argomento attuale non sara' modificato.
 */
int Potenza(int x, int n)
{
	int risultato = 1;

	while (n-- > 0)
		risultato = risultato * x;

	printf("valore di n all'interno della funzione %d\n", n);

	return risultato;
}


/* Alcune regole, stilistiche e non:
 * - Inserire il tipo restituito sopra il nome della funzione migliora la
 *   leggibilita' allorquando dovessero essere utilizzati tipi di dato piuttosto
 *   lunghi, come ad esempio potrebbe esssere <unsigned long int>.
 *
 * - Nella dichiarazione di una funzione e' possibile inserire solo il tipo di
 *   dato, senza il nome della variabile.
 *
 * - Il corpo di una funzione dichiarata void, puo' anche essere vuoto.
 *
 * - Il casting (void) e' un modo educato per dire che "non serve", se ci si
 *   trova nel caso in cui si debba scartare una funzione.
 *
 * - Gli argomenti o argomenti attuali sono passati per valore.
 */
