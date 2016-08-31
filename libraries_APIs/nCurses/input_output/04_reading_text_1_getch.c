#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(void) {
    char ch;

    initscr();
    addstr("Please type x to quit");
    refresh();

    /* getch() returns a single character from the console */
    while( (ch = getch()) != 'x') {
        printw("\ntyped: %c\n", ch);
    }

    endwin();
    exit(EXIT_SUCCESS);
}
