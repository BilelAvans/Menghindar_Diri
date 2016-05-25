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
#include "ModelObject.h"
#include "Controls/GameController.h"
#include "logic.h"

#ifdef MAC_OSX
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include "Controls/keyboard/KeyboardController.h"
#else
#include <GL/freeglut.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Controls/wiimote/wiimote.h"
#endif

#define KEY_ESCAPE 27

using namespace std;

// The objects we will be drawing
//std::vector<std::shared_ptr<Character>> characters;

float g_rotation;
glutWindow win;
GameController *w = GameController::getInstance();
int offset = 0;
int i = 0;

Player* player;

void collisionTest() {
	CollisionBox* vagina = new CollisionBox(0, 0, 0, 2, 2, 2);
	CollisionBox* lul = new CollisionBox(2, 2, 2, 2, 2, 2);
	if (lul->intersect(vagina))
	{
		printf("ja hoor hij zit erin");
	}
}
ModelObject a = ModelObject("Models/cube.obj");
struct Camera
{
	float posX = 15;
	float posY = -150;
	float rotX = 0;
	float rotY = 0;
} camera;

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(camera.posX, 0, camera.posY);

	//glRotatef(g_rotation, 0, 1, 0);
	g_rotation++;
	
	/*
	for (std::vector<shared_ptr<Character>>::iterator it = characters.begin(); it != characters.end(); it++) {
		Character temp = it._Ptr->get;
		temp.getModel().Draw();
	}
	*/

	for (int i = 0; i < 10; i++)
	{

		glColor3f(i, 1.0f, i);
		float x = enemy1[i][2];
		float y = enemy1[i][1];
		glPushMatrix();
		glTranslatef(y, 0 , x);
		a.Draw();
		glPopMatrix();
	}
	//ModelObject("Models/cube.obj").Draw();


	glutSwapBuffers();
	
}

void initialize()
{
	create(10);
	w->connect();
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
	player = new Player(0,0,0,1,1,1,new ModelObject("Models/sphere.obj"));
	player->getModelObject()->Draw();
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case KEY_ESCAPE:
		exit(0);
		break;
	case 'a':
		camera.posX++;
		break;
	case 'd':
		camera.posX--;
		break;
	default:
		break;
	}
}

void idle(){
	if (i == 60) {
		offset += w->leftRightMovement();
		posnextConti();
		i = 0;
	}
	i++;

	//repaint
	display();
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
	glutIdleFunc(idle);									// register Idle Function
	glutKeyboardFunc(keyboard);								// register Keyboard Handler
	initialize();
	w->connect();

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
