#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/* First of all include <ncurses.h> header.

To compile program linking ncurses library: 
$ gcc program.c -lncurses */

/* Skeleton of typical ncurses program */
int main(void) {
    
    /* nCurses initialization */
    initscr(); 

    /* ... source code goes here ... */

    /* close nCurses */
    endwin();
    
    return(EXIT_SUCCESS);
}
