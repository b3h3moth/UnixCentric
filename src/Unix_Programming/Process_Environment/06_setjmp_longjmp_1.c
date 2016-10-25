#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <setjmp.h>

// Function Prorotipes
void func_one(void);
void func_two(void);

// Variabile globale, conterra' l'ambiente corrente
jmp_buf env;

/* Lo scopo del programma e' di presentare un esempio di utilizzo delle
funzioni setjmp() e longjmp(). */

int main(int argc, char *argv[]) {
    int ret_sj;

    if ((ret_sj = setjmp(env)) == 0)
    	printf("setjmp() returned: %d\n", ret_sj);
    else { /* Dopo l'invocazione della funzione longjmp() l'esecuzione riprende 
    	      da questo punto */
    	printf("Program terminates: longjmp() called.\n"
	       "setjmp() returns: %d\n", ret_sj);
	return(EXIT_SUCCESS);
    }

    func_one();
    printf("program terminates normally\n");

    return(EXIT_SUCCESS);
}

void func_one(void)
{
    printf("func_one() begins\n");
    func_two();
    
    /* Le istruzioni da questo punto in poi non saranno eseguite */
    printf("func_one() returns\n");
}

void func_two(void)
{
    printf("func_two() begins\n");
    
    /* Si ritorna all'istruzione successiva alla chiamaa setjmp(), da notare
    che impostando val a 0, si avra' un valore di ritorno comunque diverso da
    0; in questo caso tuttavia si e' optato per un valore facilmente verificale
    al ritorno della setjmp(). */
    longjmp(env, 33);

    /* Le istruzioni da questo punto in poi non saranno eseguite */
    printf("func_two() returns\n");
}
