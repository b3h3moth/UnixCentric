#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/* The printw() function is the equivalent to the standard C printf() 
function. */

int main(void) {
    char version[] = "5.7";
    char os_name[] = "OpenBSD";
    
    initscr();
    printw("%s OS\n", os_name);
    printw("version number is: %s", version);
    refresh();
    getch();

    endwin();
    
    return(EXIT_SUCCESS);
}
