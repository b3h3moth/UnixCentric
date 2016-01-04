#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main(void) {
    int	r,c;
	int	cond = 1;

	initscr();

	while (1) {
        for(r=0 ; r<LINES ; r++)
            for ( c = 0 ; c<COLS; c++) {
                if (((r + c ) & 1 ) == cond)
                    standout();
                move(r, c);
                addch(' ');
                standend();
            }
        
        refresh();
        cond = !cond ;
    }
    endwin();

    return(EXIT_SUCCESS);
}
