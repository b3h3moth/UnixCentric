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
    unsigned long background = 0x00000000;
    unsigned long border = 0x00ffffff;   
    unsigned long border_width = 1;
    unsigned long height = 300;
    unsigned long width = 400;

	display = XOpenDisplay(display_name);
	screen = DefaultScreen(display);
	rootwindow = RootWindow(display, screen);
	window = XCreateSimpleWindow(display, rootwindow, 
            0, 0, width, height, border_width, border, background);
	XMapWindow(display, window);
	XFlush(display);

	sleep(3);
	XCloseDisplay(display);
	return(EXIT_SUCCESS);
}
