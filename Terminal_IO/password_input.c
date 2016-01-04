#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

// Prototipe
int get_password(char buf[], int maxlen, int star);

/* The program's purpose is to read a password in input, each character is
replaced by a '*'. 
*/

int main(void) {
    char    pass[100];
	int	    size;

	size = get_password(pass, 100, '*');
	printf("\ntyped: '%s'(%d byte)\n", pass, size);

    return(EXIT_SUCCESS);
}

int get_password(char buf[], int maxlen, int star) {
	struct termios ttystate, orig;
	int	c;
	int	pos = 0;

	tcgetattr(0, &ttystate);
	orig = ttystate;	
	ttystate.c_lflag   &= ~ICANON;
	ttystate.c_lflag   &= ~ECHO;
	ttystate.c_cc[VMIN] = 1;	
	tcsetattr(0,TCSANOW, &ttystate);

	while ((c = getchar()) != '\n' && c != '\r') {
		if (pos < maxlen-1) {
			buf[pos++] = c ;
			putchar(star);
		}
	}

	buf[pos] = '\0';
	tcsetattr(0, TCSANOW, &orig );
	
    return pos;
}
