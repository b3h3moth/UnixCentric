#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/* It writes a string (one characters at time) on the current screen 
'curscr' */

int main(void) {
    char address[] = "San lorenzo avenue";
    char *pstr;
    pstr  = address;

    initscr();

    /* Loop the string 'address' and writes each character of the string
    with addch() function */
    while(*pstr) {
        addch(*pstr);
        pstr++;
    }

    /* Update the screen */
    refresh();

    /* Wait until the user types something */
    getch();

    endwin();
    exit(EXIT_SUCCESS);
}
