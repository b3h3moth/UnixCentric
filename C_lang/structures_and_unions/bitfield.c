#include <stdio.h>
#include <stdlib.h>

/* Un membro di una struct o di una union puo' essere dichiarato come un campo
di bit (bitfield), inoltre:
- i tipi di dato associabili sono 'int' oppure 'unsigned int';
- il peso massimo consentito equivale al numero di bit della word;
- a seconda della macchina il compilatore assegna i bit da destra a sinistra
  (Little-endian) o da sinistra a destra (Big-endian);

Ci sono anche delle restrizioni:
- non sono consentiti campi di bit di array;
- l'operatore indirizzo & (address of) non e' consentito sui campi di bit, per
  cui un puntatore non puo' indirizzare uno di essi.
*/

struct date {
    unsigned int 
int main(void) {
    return(EXIT_SUCCESS);
}
