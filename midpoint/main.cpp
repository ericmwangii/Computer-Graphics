/**
* Author - Eric Mwangi
* Registration Number - SCT212-0060/2018
*/

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
float x1, x2, vy1, y2;

/**
 * implementation of the mid-point line drawing algorithm
 */

void display(void)
{
	float x, y, dy, dx, d;

	dx = x2 - x1;
	dy = y2 - vy1;

	if (dy <= dx) {
		d = dy - (dx / 2);
		x = x1;
		y = vy1;

		glBegin(GL_LINE_STRIP);
		glVertex2f(x, y);
		while (x < x2)
		{
			x++;

			if (d < 0)
				d = d + dy;
			else
			{
				d += (dy - dx);
				y++;
			}

			glBegin(GL_LINE_STRIP);
			glVertex2f(x, y);
		
		}
	}
	else if (dx < dy)
	{
		d = dx - (dy / 2);
		x = x1,
		y = vy1;

		glBegin(GL_LINE_STRIP);
		glVertex2f(x, y);

		while (y < y2)
		{
			y++;


			if (d < 0)
				d = d + dx;


			else
			{
				d += (dx - dy);
				x++;
			}

			glBegin(GL_LINE_STRIP);
			glVertex2f(x, y);
		}
	}

	glEnd();
	glFlush();


}


/**
 * init - initializes the window and the display
 * specifies the red, green, blue, and alpha values used by glClear to clear the color buffers
 * specifies which matrix is the current matrix
 * sets color of line
 * set the clipping area of 2D orthographic projection
 * set the desired scale factor for the line 
 * ensure that each time when we enter the projection mode, the matrix will be reset to identity matrix, 
 * so that the new viewing parameters are not combined with the previous one.
 */
void init(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
	glScalef(20.f, 20.f, 20.f);
}

/**
 *get the input from the user
 * initializes the window
 * sets the window size
 * sets the window title
 * sets the display function
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char* argv[]) {
	printf("Enter the value of x1 : ");
	scanf_s("%f", &x1);
	printf("Enter the value of y1 : ");
	scanf_s("%f", &vy1);
	printf("Enter the value of x2 : ");
	scanf_s("%f", &x2);
	printf("Enter the value of y2 : ");
	scanf_s("%f", &y2);

   /**
 	 *Construct a new glut Init object
  */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Mid-Point Line Drawing Algorithm");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}