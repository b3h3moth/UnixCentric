#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char *argv[])
{
	TipoVettore vett = {100,90,95,30,60,80,45,35,15,55};
	int i;

	printf("Selection sort (prima) -> ");

	for (i=0; i<MAX_VECT; i++)
		printf("%3d ", vett[i]);

	SelectionSort(vett, MAX_VECT);
	printf("\n");

	printf("Selection sort  (dopo) -> ");

	for (i=0; i<MAX_VECT; i++)
		printf("%3d ", vett[i]);

	
	return(EXIT_SUCCESS);
}
