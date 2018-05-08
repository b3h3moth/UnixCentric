#include <stdio.h>
#include <stdlib.h>

#define MAXPILA 20

/* ADT: Pila (Stack)
realizzazione sequenziale mediante vettore; pila[MAXPILA] indica il vettore
di ampiezza massima MAXPILA, pos invece indica la posizione all'interno del
vettore dell'elemento affiorante, ossia quello in cima alla pila stessa.
*/

struct structPila {
	int pila[MAXPILA];
	int pos;
};

typedef int bool;
typedef struct structPila TipoPila;

/* Inizializzazione della pila */
void InitPila(TipoPila *pila);
/* Verifica pila vuota */
bool TestPilaVuota(TipoPila pila);
/* Verifica pila pien */
bool TestPilaPiena(TipoPila pila);
/* Verifica dell'elemento affiorante della pila */
void TopPila(TipoPila pila, int *elem);
/* Inserimenti di un elemento nella pula (push) */
void Push(TipoPila *p, int elem);
/* Estrazione di un elemento dalla pila (pop) */
void Pop(TipoPila *p, int *elem);

int main(void)
{
	
	return(EXIT_SUCCESS);
}

void InitPila(TipoPila *pila)
{
	pila->pos = -1;
}

bool TestPilaVuota(TipoPila pila)
{
	/* TRUE  pila vuota, FALSE altrimenti */
	return (pila.pos == -1);
}

bool TestPilaPiena(TipoPila pila)
{
	return (pila.pos == MAXPILA-1);
}

void TopPila(TipoPila p, int *elem)
{
	if (TestPilaVuota(p))
		printf("Err. Pila vuota\n");
	else
		*elem = p.pila[p.pos];
}

void Push(TipoPila *p, int elem)
{
	if (TestPilaPiena(*p))
		printf("Err. Pila piena\n");
	else {
		p->pos++;
		p->pila[p->pos] = elem;
	}
}

void Pop(TipoPila *p, int *elem)
{
	if (TestPilaVuota(*p))
		printf("Err. Pila vuota\n");
	else {
		*elem = p->pila[p->pos];
		p->pos--;
	}
}
