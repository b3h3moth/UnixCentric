#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(void) {
    initscr();

    attron(A_BOLD);
    attrset(A_UNDERLINE);
    addstr("nCurses library is a good way to learn UNIX programming\n");
    addstr("nCurses library is a good way to learn UNIX programming\n");
    attrset(0);
    addstr("nCurses library is a good way to learn UNIX programming\n");
    refresh();
    getch();

    endwin();
    exit(EXIT_SUCCESS);
}
