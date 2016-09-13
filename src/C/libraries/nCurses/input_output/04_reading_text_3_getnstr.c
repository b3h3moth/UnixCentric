#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define MAX_STR 10

int main(void) {
    char firstname[MAX_STR];
    char lastname[MAX_STR];

    /* getnstr(char *str, int n) 
    reads from stdscr (default window) max 'n' characters, the resulting value
    is placed into the array of characters pointed by 'str' */
    
    initscr();
    addstr("Firstname: ");
    refresh();
    getnstr(firstname, MAX_STR-1);

    addstr("Lastname: ");
    refresh();
    getnstr(lastname, MAX_STR-1);


    printw("Hi, %s, %s\n", firstname, lastname);
    refresh();
    getch();

    endwin();
    exit(EXIT_SUCCESS);
}
