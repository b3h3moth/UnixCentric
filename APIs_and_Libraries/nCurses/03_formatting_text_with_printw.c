#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(void) {
    size_t version = 5.7;
    char os_name[] = "OpenBSD";
    
    initscr();
    printw("%s OS\n", os_name);
    printw("version number is: %zu", version);
    refresh();
    getch();

    endwin();
    
    return(EXIT_SUCCESS);
}
