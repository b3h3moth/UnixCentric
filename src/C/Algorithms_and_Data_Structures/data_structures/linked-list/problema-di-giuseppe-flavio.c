#include <stdio.h>
#include <stdlib.h>

/* 
Il problema di Giuseppe Flavio; si dispongono gli N componenti di un gruppo
in circolo e, a partire da uno di essi, se ne elimina uno ogni M, ne restera'
soltanto uno.

Il circolo dei componenti sara' realizzato mediante una lista concatenata
circolare, inoltre sia il numero totale dei componenti 'N' sia il numero con
cui scandire la lista 'M' sara' dinamico, ossia fornito in input.
*/

typedef int Item;

struct node {
	Item item;
	struct node *next;
};

typedef struct node *link;

int main(int argc, char *argv[]) {
	int i;
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);

	/* Si crea il t 1 con il primo componente */
	link t = malloc(sizeof(link));
	link x;
	x = t;

	t->item = 1;
	t->next = t;

	/* Si creano i nodi da 2 ad N */
	for (i=2; i<=N; i++) {
		x = (x->next = malloc(sizeof(link)));
		x->item = i;
		x->next = t;
	}

	while (x != x->next) {
		for (i=1; i<M; i++)
			x = x->next;
		x->next = x->next->next;
		N--;
	}

	printf("Resta %d\n",x->item);
	
	return(EXIT_SUCCESS);
}
