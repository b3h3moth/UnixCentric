#include <stdio.h>
#include <stdlib.h>

// MACRO PARAMETRICHE
#define MAX(x,y)	((x)>(y)?(x):(y))
#define PRINT_INT(n)	printf("%d\n", n);

int main(void) {
    int n1 = 32;
    int n2 = 28;

   /* Il comportamento del preprocessore è controllato dalle direttive di
    preprocessamento; riguarda i comandi che iniziano con #
    
    E' utile pensare al preprocessore come un componente separato rispetto
    alla compilazione
    
    Per verificare in output le direttive si può immettere l'opzione
    gcc -E al compilatore */

   printf("MAX %d\n", MAX(n1,n2));
   PRINT_INT(n1);
   PRINT_INT(n2);

   return(EXIT_SUCCESS);
}
