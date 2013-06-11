#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Puntatore a costante (Pointer to a costant)
       <const int *ptr>---------------------------
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
    <int *const ptr>------------------------
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

    /* Costante puntatore a costante (Costant pointer to costant)
       <const int *const ptr>------------------------------------
    In questo caso non e' possibile ne' sostituire il puntatore ne' modificare
    il valore dereferenziato. */
    int numint = 111;
    const int val = 222;
    
    /* L'assegnazione deve essere fatta in fase di dichiarazione del puntatore 
    altrimenti si incorrerebbe in un errore del compilatore allorquando si 
    tentera' di assegnare un indirizzo di memoria in una fase successiva, questo
    perche' si tenterebbe di assegnare un valore ad una variabile read only. */
    const int *const ptr_cst = &val;
    const int *const ptr_cst2 = &num;   /* lecito, anche se non costante */

    printf("%d - %d\n", *ptr_cst, *ptr_cst2);

    return(EXIT_SUCCESS);
}
