#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(void) {
    initscr();
    refresh();
    endwin();
    exit(EXIT_SUCCESS);
}
