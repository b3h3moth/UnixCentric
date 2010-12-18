#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
   char stringa[] = "Linux Programming";


   /* Questo metodo di 'stampare' sullo stdout e'
    * piu' efficiente, poiche' lavora solo funzioni
    * di basso livello, e oltre all'efficienza e'
    * naturalmente piu' veloce della classica printf */

   write(fileno(stdout), stringa, strlen(stringa));


   return(EXIT_SUCCESS);
}
