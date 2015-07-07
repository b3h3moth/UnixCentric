#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define MAX_STR 30

int main(void) {
    char firstname[MAX_STR];
    char lastname[MAX_STR];

    initscr();
    addstr("Firstname: ");
    refresh();
    getstr(firstname);

    addstr("Lastname: ");
    refresh();
    getstr(lastname);

    printw("Hi, %s, %s\n", firstname, lastname);
    refresh();
    getch();

    endwin();
    exit(EXIT_SUCCESS);
}
