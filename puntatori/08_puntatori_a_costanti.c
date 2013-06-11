#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Puntatore a costante (Pointer to a costant)
       -------------------------------------------
    E' perfettamente lecito definire un puntatore a costante */
    int num = 327;
    int *ptr;
    const int cnum = 89;
    const int *cptr;    /* Puntatore a costante di tipo intero; da notare che 
                           l'ordine non e' importante, l'istruzione int const *p
                           e' del tutto equivalente a const int *p. */

    /* Si assegna l'indirizzo della variabile intera num a ptr */
    ptr = &num;
    
    /* Si assegna l'indirizzo della costante intera cnum a cptr */
    cptr = &cnum;

    /* La dereferenziazione di un puntatore costante e' ammessa in sola lettura,
    non e' lecito tuttavia la modifica del valore dereferenziato:
    
    *cptr = 200; 
    Produrrebbe un errore in fase di compilazione: 
    assignment of read-only location ‘*cptr’
    */
    printf("%d\n", *cptr);

    /* Il valore del puntatore non e' costante, esso infatti puo' essere 
    associato ad un'altra locazione di memoria. */
    cptr = &num;
    printf("%d\n", *cptr);

    /* Regole per il puntatore costante 'cptr':
    - Puo' puntatore a diversi valori interi costanti;
    - Puo' puntatore a diversi valori interi non costanti;
    - Puo' essere dereferenziato in sola lettura;
    - Non puo' essere dereferenziato per la modifica del valore.
    */

    /* Costante puntatore (Constant pointer)
       ------------------------------------- 
    E' possibile definire costanti puntatore a non costanti, in questo caso
    il puntatore non puo' essere sostituito ma il valore dereferenziato puo'
    essere modificato.  */
    int num_int = 2000;
    int *const ptrc = &num_int;

    printf("%d\n", *ptrc);
    *ptrc = 2013;   /* lecito */
    printf("%d\n", *ptrc);

    /* Regole per la costante puntatore 'ptrc':
    - Deve essere inizializzato con una variabile non costante;
    - Non puo' essere modificato;
    - Il valore dereferenziato puo' essere modificato.
    */

    
    return(EXIT_SUCCESS);
}
