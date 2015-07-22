#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(void) {
    initscr();

    /* attron() turns on the named attributes without affecting any others */
    attron(A_BOLD);

    /* attrset() sets the current attributes of the given window */
    attrset(A_UNDERLINE);
    
    addstr("nCurses library is a good way to learn UNIX programming\n");
    
    /* it turns off all attributes */
    attrset(0);

    addstr("I\'m working with a lot of nice functions\n");
    
    /* attroff() turns off the named attributes without turning any other 
    attributes on or off */
    attroff(A_BOLD);
    
    refresh();
    getch();

    endwin();
    exit(EXIT_SUCCESS);
}
