#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(void) {
    char buf[] = "Take a Walk on the Wild Side";
    
    /* Stampare sullo stdout mediante la system call di basso livello write()
    risulta essere piu' efficiente rispetto alla funzione di libreria printf()
    */

   write(STDOUT_FILENO, buf, sizeof(buf));

   printf("\n");

   /* Stampa sullo stdout mediante la verifica di un'espressione condizionale 
   per constatare la correttezza del buffer stesso. */
   if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
       fprintf(stderr, "%d: %s err.\n", errno, strerror(errno));

   return(EXIT_SUCCESS);
}
