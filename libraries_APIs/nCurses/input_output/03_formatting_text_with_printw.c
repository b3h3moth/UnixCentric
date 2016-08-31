#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/* The printw() function is the equivalent to the standard C printf() 
function. */

int main(void) {
    char version[] = "5.7";
    char os_name[] = "OpenBSD";
    size_t day = 1;
    size_t month = 6;
    size_t year = 2015;
    
    initscr();
    printw("%s %s", os_name, version);
    printw(" - last update: %zu/%zu/%zu", month, day, year);
    refresh();
    getch();

    endwin();
    
    return(EXIT_SUCCESS);
}
