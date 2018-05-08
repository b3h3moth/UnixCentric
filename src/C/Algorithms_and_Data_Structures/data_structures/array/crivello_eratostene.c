#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10000


/* Il crivello di eratostene e' un metodo risalente al III secolo A.C. per il
calcolo di numeri numeri primi.

L'algoritmo: si accede a ciascun elemento dell'array mediante il proprio 
indice, dopodiche' si eliminano prima i multipli del 2, poi del 3 ed infine del
5, ottenendo in tal modo una tabella di numeri primi.

arr[i] = 1 (se e' numero primo)
arr[i] = 0 (se non e' numero primo) */

int main(void) {
	int i, j, arr[MAX_NUM];

	/* Si inizializzano tutti gli elementi dell'array ad 1 */
	for (i=2; i<MAX_NUM; i++)
		arr[i] = 1;

	/* I multipli di 2, 3 e 5 si pongono a 0 */
	for (i=2; i<MAX_NUM; i++)
		if (arr[i])
			for (j=i; i*j <MAX_NUM; j++)
				arr[i*j] = 0;

	/* Si stampano i numeri primi */
	for (i=2; i<MAX_NUM; i++)
		if (arr[i])
			printf("%4d ", i);
	printf("\n");
	
	return(EXIT_SUCCESS);
}
