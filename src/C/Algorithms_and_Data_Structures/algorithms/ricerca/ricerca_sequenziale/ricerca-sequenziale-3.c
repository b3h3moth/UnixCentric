#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 40
#define TRUE 0
#define FALSE 1

/*
L'algoritmo effettua la ricerca di un elemento all'interno di un vettore,
ritornera' TRUE se la ricerca sara' proficua, FALSE altrimenti; quando 
l'elemento sara' individuato la ricerca avra' termine

Complessita: O(n)
*/

typedef int TipoDato;
typedef TipoDato TipoVettore[MAX_SIZE];

int RicercaEsaustiva(TipoVettore vett, TipoDato elem, int n);

int main(int argc, char *argv[])
{
	TipoVettore vettore = {
		12,12,43,54,95,16,67,28,39,10,
		23,35,56,78,98,23,34,30,45,56,
		12,34,34,45,13,34,34,45,56,56,
		23,34,45,64,76,71,65,45,32,23};


	int elem = 10;
	int max_pos = 15;
	int search = RicercaEsaustiva(vettore, elem, max_pos);

	if (search == TRUE)
		printf("Elemento %d trovato tra i primi %d del vettore\n", elem, max_pos);
	else
		printf("Elemento non trovato\n");

	return(EXIT_SUCCESS);
}

int RicercaEsaustiva(TipoVettore vett, TipoDato elem, int n)
{
	int index = 0;
	int trovato = FALSE;

	do  {
		index++;
	}
	while (index < n-1 && vett[index] != elem);

	if (vett[index] == elem) {
		trovato = TRUE;
	}

	return trovato;
}
