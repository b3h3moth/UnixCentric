#include <stdio.h>
#include <stdlib.h>

int Somma(int n);

int main(int argc, char *argv[])
{
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
	 *
	 */
	
	return(EXIT_SUCCESS);
}

int Somma(int n)
{
	/* variabile locale */
	int somma = 0;

	while (n > 0)
		somma += n;

	return somma;
}
