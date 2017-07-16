#include <stdio.h>
#include <string.h>
#define MAXLINE 1000


int get_line(char s[], int lim);

int main(void) {
	int len = 0;		        /* lunghezza corrente della riga */
	int max = 0;		        /* lunghezza massima della riga */
	char line[MAXLINE];	        /* riga corrente */
	char longest[MAXLINE];	    /* la riga più lunga */

	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			strncpy(longest, line, len);	/* line -> longest */
		}
    }

	if (max > 0)
		printf("String:\n%sLength: %d\n", longest, max);

	return 0;
}

/* La funzione get_line() restituisce la riga più lunga di un file */
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}
/* es.
$ ./a.out < /etc/passwd
*/
