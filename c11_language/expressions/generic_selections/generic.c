#include <stdio.h>
#include <stdlib.h>

/* Il c11 fornisce una sorta di overloading mediante l'utilizzo della keyword
_Generic. 

Syntax:
-------------------------------------------------------------------------------
_Generic ( controlling-expression, association-list )

association-list:
    type-name: assignment-expression                                  
    default  : assignment-expression
-------------------------------------------------------------------------------
L' espressione di controllo (controlling-expression) non e' valutata, piuttosto
il suo tipo sara' comparato con i nomi dei tipi (type-name) inseriti nella 
lista delle associazioni (association-list).

Se il tipo dell'espressione di controllo e' compatibile con uno dei nomi di
tipo della lista delle associazioni allora il compilatore selezionera' 
l'espressione relativa. In caso contrario si utilizzera' l'associazione di
default.

_Generic (2.0, int: "int", double: "double", default: "nothing to do")

In tal caso la generic-selection sara' valutata come un double (2.0), per cui
il  risultato sara' la stringa letterale "double".

In pratica una "generic selection", valuta un valore in base al tipo di
input ricevuto. 

Associata alle macro trova la sua collocazione preferibile. */


#define generic_format(x)   _Generic((x),\
int: "%d\n",                             \
long:"%ld\n",                            \
float:"%f\n",                            \
double: "%f\n",                          \
default: "I don't recognize any type")

#define generic_printf(y)   printf(generic_format(y), y)

#define VEC_SIZE(v)    (sizeof(v)/sizeof(v[0]))

struct Element {
    union {
        int i;
        long l;
        float f;
        double d;
    } type;
};

int main(void) {

    struct Element *arr = malloc(sizeof(struct Element) * 4);
    arr[0].type.i = 10;
    arr[1].type.l = 9876l;
    arr[2].type.f = 4.0;
    arr[3].type.d = 867.789;

    generic_printf(arr[0].type.i);
    generic_printf(arr[1].type.l);
    generic_printf(arr[2].type.f);
    generic_printf(arr[3].type.d);

    free(arr);

    return(EXIT_SUCCESS);
}
