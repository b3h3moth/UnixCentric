#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/* First of all include <ncurses.h> header.

To compile program linking ncurses library: 
$ gcc program.c -lncurses */

int main(void) {
    initscr();
    addstr("To compile program: gcc program.c -lncurses");
    refresh();
    getch();
    endwin();
    return(EXIT_SUCCESS);
}
