#include <GL/freeglut.h>
#include <GL/gl.h>

/*
How to run source code on unix systems, for Debian GNU/Linux there are few
libraries you must install.

1) first of all upgrade system:
$ sudo apt-get update
$ sudo apt-get upgrade

2) check OpenGL version:
$ sudo apt-get install mesa-utils
$ glxinfo | grep OpenGL

3) install libraries:
$ sudo apt-get install freeglut3 freeglut3-dev binutils cmake libglew-dev g++ \
mesa-common-dev build-essential libglm-dev

4) compile files with:
$ g++ file.c -lglut -lGL -lGLEW -lGLU -o file
*/

void renderFunction ()
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glClear (GL_COLOR_BUFFER_BIT);
  glColor3f (1.0, 1.0, 1.0);
  glOrtho (-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glBegin (GL_POLYGON);
  glVertex2f (-0.5, -0.5);
  glVertex2f (-0.5, 0.5);
  glVertex2f (0.5, 0.5);
  glVertex2f (0.5, -0.5);
  glEnd ();
  glFlush ();
}

int main (int argc, char **argv)
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("OpenGL - First window demo");
  glutDisplayFunc (renderFunction);
  glutMainLoop ();

  return 0;
}
