#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/*
- attrset() sets text attributes;
-  attron() text attributes on;
- attroff() text attributes off.
*/
int main(void) {
    initscr();
    endwin();
    exit(EXIT_SUCCESS);
}
