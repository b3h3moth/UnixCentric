#include "header.h"

/* Selection sort: ordinamento per selezione del minimo
 *******************************************************************************
 * Complessita' : O(n^2) 
 * Ordina i primi n elementi del vettore V, cercando l'elemento piu' piccolo del
 * vettore portandolo in prima posizione V[0], dopodichè si cerca ancora 
 * l'elemento piu' piccolo compreso tra V[1] ed V[n-1], anch'esso si sposta in 
 * posizione 1, e cosi' via per per gli altri elementi.
 */

void SelectionSort(TipoVettore V, int n)
{
	int i, j, i_min;

	ElemTipoVettore temp;

	for (i=0; i<n-1; i++) {
		i_min = i;

		for (j=i+1; j<n; j++)
			if (V[j] < V[i_min])
				i_min = j;

		if (i != i_min) {
			temp = V[i_min];
			V[i_min] = V[i];
			V[i] = temp;
		}
	}
}
