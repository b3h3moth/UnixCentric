#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#define MAX_STR 20

int main(void) {
    char firstname[MAX_STR];
    char lastname[MAX_STR];
    
    initscr();

    /* scanw() is analogous to the scanf() functions family. */

    printw("Please your firstname: ");
    scanw("%s", firstname);

    printw("Please your lastname: ");
    scanw("%s", lastname);
    
    printw("Hi %s %s\n", firstname, lastname);

    refresh();
    getch();
    
    endwin();
    
    exit(EXIT_SUCCESS);
}
