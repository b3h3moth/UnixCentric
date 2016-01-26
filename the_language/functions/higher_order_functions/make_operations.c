#include <stdio.h>
#include <stdlib.h>

// Prototipi
int make_operations(int val1, int val2, int (*func)(int, int));
// A supporto della funzione make_operations().
int addition(int val1, int val2);
int subtraction(int val1, int val2);
int multiplication(int val1, int val2);
int division(int val1, int val2);

/* L'intero programma ruoto attorno alla funzione generica make_operations(),
che e' in grado di eseguire diverse operazioni tra due valori mediante la
funzione int (*func)(int, int) passata come argomento. */

int main(void) {
    return(EXIT_SUCCESS);
}


int addition(int val1, int val2) {
    return (val1 + val2);
}

int subtraction(int val1, int val2);
    return (val1 - val2);
}

int multiplication(int val1, int val2);
    return (val1 * val2);
}

int division(int val1, int val2);
    return (val1 / val2);
}
