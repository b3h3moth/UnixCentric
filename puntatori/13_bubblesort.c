#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void bubble(int work[], const int size, int (*compare)(int x, int y));
int ascending(int x, int y);
int descending(int x, int y);
void swap(int *elem1, int *elem2);

/* Scopo: Il programma ordina in maniera ascendente o discente un vettore */
int main(void) {
    /* valore per definire il modo di ordinamento, 
    1 ascendente, 2 discendente, e variabile contatore*/
    int order, i;

    int vec[MAX_SIZE] = {2,23,5,76,34,8,16,78,39,10,19,7,87,73,4,11,82,49,0,1};

    printf("> Scegli il tipo di ordinamento (1 ascendente - 2 discentente): ");
    scanf("%1d", &order);

    printf("\nDati dell'array nell'ordine iniziale:\n");
    for(i=0; i<MAX_SIZE; i++)
        printf("%4d", vec[i]);

    /* ordine ascendente */
    if (order == 1) {
        bubble(vec, MAX_SIZE, ascending);
        printf("\n\nDati ordinati in modo ascendente:\n");
    } else if (order == 2) {
        bubble(vec, MAX_SIZE, descending);
        printf("\n\nDati ordinati in modo discendente:\n");
    } else {
        printf("\n\n>>> Err: Le opzioni sono 1 e 2\n");
        exit(EXIT_FAILURE);
    }

    /* Visualizzazione del verrore ordinato */
    for (i=0; i<MAX_SIZE; i++)
        printf("%4d", vec[i]);

    return(EXIT_SUCCESS);
}

/* Ordinamento a bolle (bubble sort) */
void bubble(int work[], const int size, int (*compare)(int x, int y))
{
    int pass;   /* conta i passaggi */
    int count;  /* conta i confronti */

    /* Si contano i passaggi */
    for (pass = 1; pass<size; pass++) {
        /* si controllano i confronti per ciascun passaggio */
        for (count = 0; count<size-1; count++) {
            /* scambia elementi adiacenti se non sono in ordine */
            if ((*compare)(work[count], work[count+1])) {
                swap (&work[count], &work[count+1]);
            }
        }
    }
}

int ascending(int x, int y)
{
    return y < x;
}

int descending(int x, int y)
{
    return y > x;
}

void swap(int *elem1, int *elem2)
{
    int temp;
    temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}
