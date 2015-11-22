#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

void print_bit(unsigned int bit_size, unsigned int bit_field);

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
    Gli interi disponibili sono 2^5, ovvero da 0 a 31.
    I giorni vanno da 1 a 31, per cui e' perfetto. */
    unsigned int day: 5;

    /* Campo per salvare il mese su 4 bit.
    Gli interi disponibili sono 2^4, ovvero da 0 a 16.
    I mesi vanno da 1 a 12, avanzano 4 bit. */
    unsigned int month: 4;
    
    /* Campo per salvare l'anno su 11 bit.
    Gli interi disponibili sono 2^11, ovvero da 0 a 2048.
    Siamo nel 2015, e fino al 2048 c'e' tempo.  */
    unsigned int year: 11;
    
    /* Campo per salvare l'ora su 5 bit.
    Gli interi disponibili sono 2^5, ovvero da 0 a 31.
    Le ore vanno da 1 a 24, avanzano 7 bit.  */
    unsigned int hour: 5;
    
    /* Campo per salvare i minuti su 4 bit.
    Gli interi disponibili sono 2^6, ovvero da 0 a 64.
    I minuti vanno da 0 a 60, avanzano 4 bit. */
    unsigned int min: 6;

} Date;

/* Il nuovo tipo Date e' caratterizzato da 5 campi di bit dal peso complessivo
di 30 bit, tuttavia il compilatore allochera' 32 bit per allinearla alla 
word dell'architettura. */

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

    printf("Today's date is:\n");
    
    printf("%5s: %4d - binary: ", "Day", today.day);
    print_bit(5, today.day);

    fputc('\n', stdout);
    
    printf("%5s: %4d - binary: ", "Month", today.month);
    print_bit(4, today.month);

    fputc('\n', stdout);
    
    printf("%5s: %4d - binary: ", "Year", today.year);
    print_bit(11, today.year);

    return(EXIT_SUCCESS);
}

void print_bit(unsigned int bit_size, unsigned int bit_field) {
    int mask = 1 << (bit_size - 1); // Work on Most Significant Bit

    for (int i=1; i<=bit_size; ++i) {
        fputc((bit_field & mask) == 0 ? '0': '1', stdout);
        bit_field <<= 1;
    }
}
