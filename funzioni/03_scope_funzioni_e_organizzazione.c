#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /* solo C99 */


/* Massima ampiezza dello stack */
#define STACK_SIZE 10


/* VARIABILI ESTERNE O GLOBALI
 *
 * Vettore utilizzato per memorizzare gli elementi dello stack */
int contenuto[STACK_SIZE];

/* Indica la posizione in cima allo stack */
int top = 0;


/* PROTOTIPI DELLE FUNZIONI */
int Somma(int n);
int Potenza(int n, int x);
int Incrementa(void);
int Decrementa();

/* Prototipi inerenti l'implementazione dello stack */
void SvuotaStack(void);
bool StackVuoto(void);
bool StackPieno(void);
void push(int i);
void pop(void);
void StampaStack(void);


int main(int argc, char *argv[])
{
	int somma = 5, i;

	/* VARIABILI LOCALI
	 ***************************************************************************
	 * Una variabile dichiarata nel corpo di una funzione e' detta come locale 
	 * alla funzione stessa; nel caso della funzione Somma(), la variabile somma
	 * e' una variabile locale, esse godono di specifiche proprieta':
	 *
	 * - Durata di memorizzazione automatica.
	 *   Nasce e muore all'interno del blocco di una funzione, ossia la memoria
	 *   viene allocata automaticamente al momento dell'invocazione della
	 *   funzione e deallocata non appena la funzione termina, il suo valore
	 *   pertanto sara' indefinito qualora si dovesse invocare nuovamente la
	 *   funziuone;
	 * 
	 * - Ambito di visibilita' al livello di blocco (o scope di blocco).
	 *   Lo scope e' quella parte del programma che puo' far riferimento alla
	 *   variabile, ovvero i limiti entro i quali una variabile e' visibile. 
	 *   Le variabili locali pertanto hanno scope di blocco, sono visibili solo 
	 *   all'interno del blocco in cui sono state dichiarate, all'esterno di 
	 *   esso peraltro possono esserci anche altre variabili con lo stesso nome,
	 *   e non ci sara' conflitto. 
	 *
	 *   I parametri di una funzione hanno anch'essi scope di blocco e durata di
	 *   memorizzazione automatica, l'unica differenza con le variabili
	 *   dichiarate all'interno di una funzione e' che i parametri sono
	 *   inizializzati automaticamente con il valore degli argomenti all'atto
	 *   dell'invocazione della funzione.
	 */

	printf("var somma scope Somma(): %d\n", Somma(somma));
	printf(" var somma scope main(): %d\n", somma);

	/* VARIABILI STATICHE LOCALI
	 ***************************************************************************
	 * Se si aggiunge la parola chiave static ad una variabile locale, essa non
	 * perdera' il suo valore poiche' avra' a disposizione una locazione di
	 * memoria per tutta la durata del programma, peraltro la durata di
	 * memorizzazione diventera' statica.
	 *
	 * Lo scope naturalmente e' di blocco, poiche' e' sempre una variabile
	 * locale.
	 *
	 * Come si evince dalla funzione Incrementa(), ad ogni invocazione la
	 * variabile static avra' il valore precedentemente salvato, cio' che invece
	 * non avviene nella funzione Decrementa().
	 */

	for (i=0; i<10; i++)
		printf("int static i: %d - int i %d\n", Incrementa(), Decrementa());

	/* VARIABILI GLOBALI (o esterne)
	 ***************************************************************************
	 * Le variabili esterne o globali sono dichiarate fuori dal corpo di
	 * qualsiasi funzione:
	 *
	 * - Durata della memorizzazione statica.
	 *   Si comportano esattamente come le variabili statiche locali, per cui
	 *   la locazione di memoria assegnata ad esse sara' valida per tutta la
	 *   durata del programma.
	 *
	 * - Scopo di file, ovvero una variabile globale e' visibile dal punto in
	 *   cui e' stata dichiarata fino alla fine del file.
	 * 
	 * Si implementa ora uno stack (LIFO) per verificarne il comportamento.
	 */
	printf("Test dello stack\n");

	if ( StackVuoto() ) {
		push(10);
	}
	
	push(20), push(30), push(40), push(50);

	if ( StackPieno() ) {
		pop();
	}
	
	StampaStack();
	push(60), push(70), push(80), push(90), push(100);
	StampaStack();

	if ( StackVuoto() ) {
		push(200);
	}

	pop(), pop(), pop(), pop();
	StampaStack();

	/* 
	 * Da notare, infine, che l'uso delle variabili globali non e' una pratica
	 * consigliata in seno alla programmazione C, poiche', piuttosto che
	 * condividere variabili esterne per la comunicazione tra funzioni, e'
	 * consigliato utilizzare per tale comunicazione i parametri delle funzioni.
	 */

	/* ORGANIZZAZIONE DI UN PROGRAMMA C
	 ***************************************************************************
	 * Tenendo comunque conto che un programma C di grosse dimensioni andrebbe
	 * suddiviso in diversi file, ora si fornira' un consiglio su quale potrebbe
	 * essere il modo corretto per organizzare un listato:
	 *
	 * Direttive #include 
	 * Direttive #define
	 * Definizioni di tipo
	 * Dichiarazione variabili globali
	 * Prototipi delle funzioni
	 * Definizione del main()
	 * Definizione delle funzioni
	 */

	return(EXIT_SUCCESS);
}


/* Implementata per verificare il comportamento di variabili locali */
int Somma(int n)
{
	/* variabile locale */
	int somma = 0;

	while (--n > 0)
		somma += n;

	return somma;
}

/* Sviluppata per comprendere il comportamento di una variabile locale
 * dichiarata statici */
int Incrementa()
{
	static int i;

	return ++i;
}

/* La differenza con la funzione Incrementa() e' del tutto evidente, in questo
 * caso la variabile locale non conservera' il suo valore, poiche' alla fine del
 * blocco sara' deallocata la memoria ad essa assegnata */
int Decrementa()
{
	int i = 10;

	return --i;
}

/* DEFINIZIONE DELLE FUNZIONI DELLO STACK
 * Svuota lo stack */
void SvuotaStack(void)
{
	top = 0;
}

/* Verifica se lo stack e' vuoto */
bool StackVuoto(void)
{
	return top == 0;
}

/* Verifica se lo stack e' pieno */
bool StackPieno(void)
{
	return top == STACK_SIZE;
}

/* Inserisce un elemento in cima allo stack */
void push(int i)
{
	if ( StackPieno() )
		exit(EXIT_FAILURE);
	else
		contenuto[top++] = i;
}

/* Elimina un elemento dalla cima dello stack */
void pop(void)
{
	contenuto[top] = 0;
	contenuto[--top];
}

/* Stampa tutti gli elementi dello stack, quelli con contenuto 0 li salta.
 * Si ricordi che questo e' un esempio per verificare il funzionamento delle
 * variabili globali, non sugli slgoritmi e strutture dati, per cui si invita
 * a non considerare l'implementazione della struttura dati Stack (LIFO) 
 * impeccabile dal punto di vista logico. */
void StampaStack(void)
{
	int i;

	for(i = 0; i<STACK_SIZE; i++) {
		if (contenuto[i] == 0)
			continue;
		printf("%d\n", contenuto[i]);
	}
	printf("----------\n");
}
