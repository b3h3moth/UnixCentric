#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // da C99

// Massima ampiezza dello stack
#define STACK_SIZE 10

/* variabili esterne o globali
Vettore utilizzato per memorizzare gli elementi dello stack */
int contenuto[STACK_SIZE];

// Indica la posizione in cima allo stack
int top = 0;

// Prototipi
int Somma(int n);
int Potenza(int n, int x);
int Incrementa(void);
int Decrementa();

// Prototipi inerenti l'implementazione dello stack
void SvuotaStack(void);
bool StackVuoto(void);
bool StackPieno(void);
void push(int i);
void pop(void);
void StampaStack(void);


int main(int argc, char *argv[]) {
    int somma = 5, i;

	printf("var somma scope Somma(): %d\n", Somma(somma));
	printf(" var somma scope main(): %d\n", somma);

	for (i=0; i<10; i++)
		printf("int static i: %d - int i %d\n", Incrementa(), Decrementa());

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
 * dichiarata statica */
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
