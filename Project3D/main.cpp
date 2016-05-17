#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include "Character.h"
#include "Player.h"
#include "wiimote.h"
#include "ModelObject.h"
#include <GL\freeglut.h>

#ifndef MAC_OSX
//#include <OpenGL/OpenGL.h>
//#include <GLUT/glut.h>

#else
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#define KEY_ESCAPE 27

using namespace std;

// The objects we will be drawing
//std::vector<std::shared_ptr<Character>> characters;

float g_rotation;
glutWindow win;
wiimote w;
double offset = 0;
int i = 0;
struct Camera
{
	float posX = 4;
	float posY = -10;
	float rotX = 0;
	float rotY = 0;
} camera;
void checkWiiBoard() {
	w.RefreshState();
	double weightL = w.BalanceBoard.Kg.BottomL + w.BalanceBoard.Kg.TopL;
	double weightR = w.BalanceBoard.Kg.BottomR + w.BalanceBoard.Kg.TopR;
	printf("%d", weightR);
	if (weightR + 10 < weightL) {
		printf("Going left");
		offset--;
	}
	if (weightL + 10 < weightR) {
		printf("going right");
		offset++;
	}
}
void display()
{
	if (i == 100) {
		checkWiiBoard();
		//offset+=0.5f;
		i = 0;
	}
	i++;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(camera.rotX, 1, 0, 0);
	glRotatef(camera.rotY, 0, 1, 0);
	glTranslatef(camera.posX+offset, 0, camera.posY);
	glPushMatrix();
	//glRotatef(g_rotation, 0, 1, 0);
	g_rotation++;
	
	/*
	for (std::vector<shared_ptr<Character>>::iterator it = characters.begin(); it != characters.end(); it++) {
		Character temp = it._Ptr->get;
		temp.getModel().Draw();
	}
	*/
	ModelObject("Models/cube.obj").Draw();
	//ModelObject("Models/cube.obj").Draw();

	glPopMatrix();
	glutSwapBuffers();
	
}

void initialize()
{
	w.CalibrateAtRest();
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, win.width, win.height);
	GLfloat aspect = (GLfloat)win.width / win.height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);
	glMatrixMode(GL_MODELVIEW);
	//glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.1f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
	
	// Light 1
	GLfloat amb_light[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat diffuse[] = { 0.6, 0.6, 0.6, 1 };
	GLfloat specular[] = { 0.7, 0.7, 0.3, 1 };

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb_light);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glEnable(GL_LIGHT0);
	
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case KEY_ESCAPE:
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char **argv)
{
	// set window values
	win.width = 640;
	win.height = 480;
	win.title = "Menghindar? DIRI?!?!.";
	win.field_of_view_angle = 45;
	win.z_near = 1.0f;
	win.z_far = 500.0f;

	// initialize and run program
	glutInit(&argc, argv);                                      // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);  // Display Mode
	glutInitWindowSize(win.width, win.height);					// set window size
	glutCreateWindow(win.title);								// create Window
	glutDisplayFunc(display);									// register Display Function
	glutIdleFunc(display);									// register Idle Function
	glutKeyboardFunc(keyboard);								// register Keyboard Handler
	initialize();
	w.Connect();

	
	
	


	// Load objects
	//ModelObject ob = ModelObject("Models/sphere.obj");
	//ob.Move();
	//ob.Release();
	//blenderObjects.push_back(ob);
	//std::shared_ptr<Player> player = make_shared<Player>(Player("Bilel"));
	
	//characters.emplace_back(player);

	glutMainLoop();												// run GLUT mainloop
	return 0;
}
