#include <stdlib.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <unistd.h>

/* Lo scopo del programma e' la creazione di una 'window'.

Per compilare il programma:
$ gcc (clang) window.c -L/usr/X11R6/lib -lX11 -std=c11 -Wall -pedantic
*/

int main(void) {
    Display *display;
	Window window, rootwindow;
	int screen;
    char *name = ":0.0";

	display = XOpenDisplay(name);
	screen = DefaultScreen(display);
	rootwindow = RootWindow(display, screen);
	window = XCreateSimpleWindow(display, rootwindow, 0, 0, 100, 100, 1, 0, 0);
	XMapWindow(display, window);
	XFlush(display);

	sleep(3);
	XCloseDisplay(display);
	return(EXIT_SUCCESS);
}
