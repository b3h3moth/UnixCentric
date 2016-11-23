#include <stdlib.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <unistd.h>

/* Lo scopo del programma e' la creazione di una 'window' di 400x400px

Per compilare il programma:
$ gcc (clang) window.c -L/usr/X11R6/lib -lX11 -std=c11 -Wall -pedantic
*/

int main(void) {
    Display *display;
	Window window, rootwindow;
	int screen;
    char *display_name = ":0.0";
    unsigned long background = 0x00ff9944;  // Orange bg

	display = XOpenDisplay(display_name);
	screen = DefaultScreen(display);
	rootwindow = RootWindow(display, screen);
	window = XCreateSimpleWindow(display, rootwindow, 
            0, 0, 400, 400, 1, 0, background);
	XMapWindow(display, window);
	XFlush(display);

	sleep(3);
	XCloseDisplay(display);
	return(EXIT_SUCCESS);
}
