#include <GL/freeglut.h>
#include <GL/gl.h>


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
