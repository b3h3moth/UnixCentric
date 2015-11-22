#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

void print_bit(unsigned int bit_size, unsigned int bit_field) {

/* Un membro di una struct o di una union puo' essere dichiarato come un campo
di bit (bitfield), inoltre:
- i tipi di dato associabili devono essere 'int' oppure 'unsigned int';
- dal c99 (iso9899:1999) e' consentito anche il tipo di dato _Bool;
- il peso massimo consentito equivale al numero di bit della word;
- a seconda della macchina il compilatore assegna i bit da destra a sinistra
  (Little-endian) o da sinistra a destra (Big-endian);
- sono consentiti campi di bit impostati a zero;
- sono consentiti campi di bit privi di identificatore.

Ci sono anche delle restrizioni:
- non sono consentiti campi di bit di array;
- l'operatore indirizzo & (address of) non e' consentito sui campi di bit, per
  cui un puntatore non puo' indirizzare uno di essi.
*/

typedef struct {
    /* Campo per salvare il giorno su 5 bit.
    Gli interi disponibili sono 2^5, ovvero da 0 a 31 */
    unsigned int day: 5;    
    /* Campo per salvare il mese su 4 bit.
    Gli interi disponibili sono 2^4, ovvero da 0 a 16 */
    unsigned int month: 4;
    /* Campo per salvare l'anno su 11 bit.
    Gli interi disponibili sono 2^11, ovvero da 0 a 2048, fino al 2048  */
    unsigned int year: 11;
    unsigned int :13;
} Date;

int main(void) {
    time_t t;
    struct tm *lt;
    Date today;
    
    if ((t = time(NULL)) < 0) {
        fprintf(stderr,"Err.(%s) getting time\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    lt = gmtime(&t);

    today.day = lt->tm_mday;
    today.month = lt->tm_mon;
    today.year = 1900 + lt->tm_year;

    printf("Today's date is: %d ", today.day);
    print_bit(5, today.day);

    return(EXIT_SUCCESS);
}

void print_bit(unsigned int bit_size, unsigned int bit_field) {
    int mask = 1 << (bit_size - 1); // Work on Most Significant Bit

    for (int i=1; i<=bit_size; ++i) {
        fputc((bit_field & mask) == 0 ? '0': '1', stdout);
        bit_field <<= 1;
        if ((i % 8 == 0) && (i != 0))
            fputc(' ', stdout);
    }
}
