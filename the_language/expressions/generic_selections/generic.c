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

int main(void) {
   
    printf("%s\n", _Generic (2.0, int: "int", 
                                  double: "double", 
                                  default: "nothing to do") );
    
    return(EXIT_SUCCESS);
}
