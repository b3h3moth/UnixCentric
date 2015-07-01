#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/* It writes a string on the current screen 'curscr' */

int main(void) {
    char address[] = "Fifth avenue NY ";
    char msg_to_text[] = "(type something to exit)";

    initscr();

    /* Write the two strings with addstr() function */
    addstr(address);
    addstr(msg_to_text);

    /* Update the screen */
    refresh();

    /* Wait until the user types something */
    getch();

    endwin();
    exit(EXIT_SUCCESS);
}
