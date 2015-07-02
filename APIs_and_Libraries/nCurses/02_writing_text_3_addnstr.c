#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

/* It writes a string on the current screen 'curscr' with addnstr() function.

int addnstr(const char *str, int n);
write a string large exaclty n characters. */

int main(void) {
    char message[] = "Unix addicted\n";
    char msg_help[] = "(type something to exit)\n";

    initscr();

    addnstr(message, strlen(message));
    addnstr(msg_help, strlen(msg_help));

    refresh();
    getch();

    endwin();
  
    exit(EXIT_SUCCESS);
}
