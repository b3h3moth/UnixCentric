#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/* Quando si dichiara una funzione con un parametro formale di tipo array, ad
esempio 'function(int data[])', il parametro formale data[] viene letto dal
compilatore 'int *data', ovvero come se fosse un puntatore. Tale comportamento
avviene solo nel contesto della dichiarazione di un parametro formale. */

int sum(int data[], int len);
/* Prototipi di funzione equivalenti:
int sum(int data*, int len);
int sum(int [], int len);
int sum(int *, int len);
*/

int main(void) {
    int list_of_numbers[] = {10, 20, 30, 40, 50};

    printf("[main()] array size: %zu byte\n", sizeof(list_of_numbers) );

    int result = sum(list_of_numbers, SIZE);

    printf("sum of each array element: %d\n", result);

    return(EXIT_SUCCESS);
}

// La funzione sum(), somma ciascune elemento del vettore
int sum(int data[], int len) {
    printf("[ sum()] array size: %zu byte\n", sizeof(data) );

    int res = *data;

    for (int *p = data +1; p < data + len; p++)
        res += *p;
    
    return res;
}
