#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR_SIZE 40
#define TRUE 0
#define FALSE 1

/*
L'algoritmo effettua la ricerca dell'elemento 'elem' all'interno dei primni 'n'
elementi del vettore 'vett', che ritornera' TRUE se l'esito della ricerca sara'
positivo, FALSE altrimenti, inoltre, qualora 'elem' fosse presente nel vettore,
all'interno della variabile di tipo intero 'pos' sara' inserito l'indice della
posizione dell'elemento trovato.

La ricerca terminera' non appena sara' individuato l'elemento.

Complessita: O(n)
*/

typedef int TipoDato;
typedef TipoDato TipoVettore[MAX_ARR_SIZE];

int RicercaSequenziale(TipoVettore vett, TipoDato elem, int n, int *pos);

int main(int argc, char *argv[])
{
	TipoVettore vettore;
	int i, j;

	/* Riempie un array di MAX_ARR_SIZE elementi con valori casuali che 
       vanno da 1 a MAX_ARR_SIZE */
	for (i=0; i<MAX_ARR_SIZE; i++)
		vettore[i] = MAX_ARR_SIZE*(1.0*rand()/RAND_MAX);

	int elem;

	/* Poiche' il vettore e' riempito con numeri casuali si e' preferito
	eseguire la ricerca considerando l'intera ampiezza del vettore stesso  */
	int max_pos = MAX_ARR_SIZE;
	int posizione;
	int searching;

	/* Invece di fornire un valore iniziale, si ciclano MAX_ARR_SIZE valori
	   casuali, compresi tra 1 e 40, la ricerca pertanto sara' eseguita su
	   questi valori */
	for (j=0; j<MAX_ARR_SIZE; j++) {
            elem = MAX_ARR_SIZE*(1.0*rand()/RAND_MAX);
            searching = RicercaSequenziale(vettore, elem, max_pos, &posizione);
            
            if (searching == TRUE)
                printf("Trovato l'intero \"%d\" tra i primi \"%d\". "
                       "In posizione \"%d\" del vettore.\n",
                       elem, max_pos, posizione);
            else
                printf("Intero %d non trovato\n", elem);
        }
        
        return(EXIT_SUCCESS);
}

int RicercaSequenziale(TipoVettore vett, TipoDato elem, int n, int *pos)
{
	int index = 0;
	int trovato = FALSE;

	/* Si e' preferito inserire le parentesi graffe per rendere chiara
	   l'istruzione do-while */

	do  {
		index++;
	}
	while (index < n-1 && vett[index] != elem);

	if (vett[index] == elem) {
		trovato = TRUE;
		// L'indice del vettore in cui si trova l'elemento
		*pos = index;
	}

	return trovato;
}
