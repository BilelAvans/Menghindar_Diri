#include <math.h>

#include <gl/freeglut.h>

#define PI 3.14159

void init();
void display(void);
void centerOnScreen();
void drawObject();
void drawCircle(int straal);

//  define the window position on screen
int window_x;
int window_y;

//  variables representing the window size
int window_width = 800;
int window_height = 800;

//  variable representing the window title
char *window_title = "Menghindar? DIRI?!?!";

//-------------------------------------------------------------------------
//  Program Main method.
//-------------------------------------------------------------------------
void main(int argc, char **argv)
{
	//  Connect to the windowing system + create a window
	//  with the specified dimensions and position
	//  + set the display mode + specify the window title.
	glutInit(&argc, argv);
	centerOnScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_x, window_y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow(window_title);

	//  Set OpenGL program initial state.
	init();

	// Set the callback functions
	glutDisplayFunc(display);

	//  Start GLUT event processing loop
	glutMainLoop();
}

void init()
{
	//  Set the frame buffer clear color to black. 
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

//-------------------------------------------------------------------------
void display(void)
{
	//  Clear the window or more specifically the frame buffer...
	//  This happens by replacing all the contents of the frame
	//  buffer by the clear color (black in our case)
	glClear(GL_COLOR_BUFFER_BIT);

	//  Draw object
	drawCircle(1);

	//  Swap contents of backward and forward frame buffers
	glutSwapBuffers();
}

void drawObject()
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);

	glEnd();

}

void drawCircle(int straal) {

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);

	for (int angle = 0; angle < 360; angle++) {
		glVertex3f(straal * cos(angle), straal * sin(angle), 0.0f);
	}

	glEnd();
	
}

void centerOnScreen()
{
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
}