/**
* Author - Eric Mwangi
* Registration Number - SCT212-0060/2018
*/

#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
float x1, x2, vy1, y2;

/**
 * implementation of bresenam's line drawing algorithm
 */

void display(void)
{
    float M, p, dx, dy, x, y, t;

    if ((x2 - x1) == 0)
        M = (y2 - vy1);
    else
        M = (y2 - vy1) / (x2 - x1);

    if (fabs(M) < 1)
    {
        if (x1 > x2)
        {
            t = x1;
            x1 = x2;
            x2 = t;

            t = vy1;
            vy1 = y2;
            y2 = t;
        }

        dx = fabs(x2 - x1);
        dy = fabs(y2 - vy1);

        p = 2 * dy - dx;

        x = x1;
        y = vy1;

        glBegin(GL_LINE_STRIP);
        while (x <= x2)
        {
            glVertex2f(x, y);
            x = x + 1;

            if (p >= 0)
            {
                if (M < 1)
                    y = y + 1;
                else
                    y = y - 1;
                p = p + 2 * dy - 2 * dx;
            }
            else
            {
                y = y;
                p = p + 2 * dy;
            }
        }
        glEnd();
    }

    if (fabs(M) >= 1)
    {
        if (vy1 > y2)
        {
            t = x1;
            x1 = x2;
            x2 = t;

            t = vy1;
            vy1 = y2;
            y2 = t;
        }

        dx = fabs(x2 - x1);
        dy = fabs(y2 - vy1);

        p = 2 * dx - dy;

        x = x1;
        y = vy1;


        glBegin(GL_LINE_STRIP);
        while (y <= y2)
        {
            glVertex2f(x, y);
            y = y + 1;

            if (p >= 0)
            {
                if (M >= 1)
                    x = x + 1;
                else
                    x = x - 1;
                p = p + 2 * dx - 2 * dy;
            }
            else
            {
                x = x;
                p = p + 2 * dx;
            }
        }
        glEnd();
    }

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
int main(int argc, char* argv[])
{
    printf("Enter the value of x1 : ");
    scanf_s("%f", &x1);
    printf("Enter the value of y1 : ");
    scanf_s("%f", &vy1);
    printf("Enter the value of x2 : ");
    scanf_s("%f", &x2);
    printf("Enter the value of y2 : ");
    scanf_s("%f", &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
