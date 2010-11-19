#include <stdio.h>
#include <stdlib.h>


/* Prototipi delle funzioni */
int Somma(int n);
int Potenza(int n, int x);
int Incrementa(void);
int Decrementa();


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

	/* VARIABILI STATICHE (locali)
	 ***************************************************************************
	 * Se si aggiunge la parola chiave static ad una variabile locale, essa non
	 * perdera' il suo valore poiche' avra' a disposizione una locazione di
	 * memoria per tutta la durata del programma, pertanto la durata di
	 * memorizzazione diventera' statica.
	 *
	 * Lo scope naturalmente e' di blocco, poiche' e' sempre una variabile
	 * locale.
	 *
	 * Come si evince dalla funzione Incrementa(), ad ogni invocazione la
	 * variavile static avra' il valore precedentemente salvato, cio' che invece
	 * non avviene nella funzione Decrementa().
	 */

	for (i=0; i<10; i++)
		printf("int static i: %d - int i %d\n", Incrementa(), Decrementa());

	
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
