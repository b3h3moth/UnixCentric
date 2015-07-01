#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(void) {
    char string[] = "Writing nCurses program";
    char *pstr;
    pstr  = string;

    initscr();

    while(*pstr) {
        /* addch() writes characters on the current screen, curstr */
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
