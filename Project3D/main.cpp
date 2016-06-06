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
#include "SoundPlayer.h"
#include <thread>
#include "Skybox.h"
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <zconf.h>
#include "Controls/keyboard/KeyboardController.h"
#include "Objects/node/Node.h"

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
Node *a;
//= ModelObject((char *) "Models/lowPolyAirplane/lowPolyAirplane.obj");
struct Camera
{
	float posX = 10;
	float posY = -170; //-150 default
	float posZ = -10;
	float rotX = 0;
	float rotY = 0;
} camera;

Node *node;

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	//skybox
	glPushMatrix();
	glRotatef(180, 1, 0, 0);
	drawSkybox(400.0);
	glPopMatrix();

	glTranslatef(camera.posX, camera.posZ, camera.posY);

	//HUD
	glutStrokeCharacter(GLUT_STROKE_ROMAN, player->score);


	//glRotatef(g_rotation, 0, 1, 0);
	g_rotation++;
	glRotatef(camera.rotX, 1, 0, 0);
	glRotatef(camera.rotY, 0, 1, 0);
	/*
	for (std::vector<shared_ptr<Character>>::iterator it = characters.begin(); it != characters.end(); it++) {
		Character temp = it._Ptr->get;
		temp.getModel().Draw();
	}
	*/

	for (int i = 0; i < 10; i++)
	{

//		glColor3f((GLfloat)i, (GLfloat)1.0f, (GLfloat)i);
		glPushMatrix();
		enemybuffer1[i].Draw();
		glPopMatrix();
	}
//	ModelObject("Models/cube.obj").Draw();


	player->Draw();

	node->draw();
	glutSwapBuffers();
	
}

void mousePassiveMotion(int x, int y)
{
//	int dx = x - win.width / 2;
//	int dy = y - win.height / 2;
//	if ((dx != 0 || dy != 0) && abs(dx) < 400 && abs(dy) < 400)
//	{
//		camera.rotY += dx / 10.0f;
//		camera.rotX += dy / 10.0f;
//		glutWarpPointer(win.width / 2, win.height / 2);
//	}
}

void initialize()
{
	init();
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
	glEnable(GL_TEXTURE_2D);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
	glutWarpPointer(win.width/2,win.height/2);

	node = new Node(new ObjModel("Models/bloemetje/PrimroseP.obj"));
	a = new Node(new ObjModel("Models/bloemetje/PrimroseP.obj"));


	// Light 1
	GLfloat amb_light[] = { (GLfloat)0.1, (GLfloat)0.1, (GLfloat)0.1, (GLfloat)1.0 };
	GLfloat diffuse[] = { (GLfloat)0.6, (GLfloat)0.6, (GLfloat)0.6, (GLfloat)1 };
	GLfloat specular[] = { (GLfloat)0.7,(GLfloat) 0.7,(GLfloat) 0.3, (GLfloat)1 };

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
	player = new Player(-10,0,130,1,1,1,new Node(new ObjModel("Models/lowPolyAirplane/lowPolyAirplane.obj")));
//	player = new Player(-10,0,130,1,1,1,new Node(new ObjModel("Models/bloemetje/PrimroseP.obj")));

	initSkybox();
	//player = new Player(-10,0,130,1,1,1,new ModelObject("Models/lowPolyAirplane/lowPolyAirplane.obj"));

}


void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case KEY_ESCAPE:
		exit(0);
		break;
	case 'a':
//		camera.posX++;
			player->move(-1, 0, 0);
		break;
	case 'd':
//		camera.posX--;
			player->move(1, 0, 0);
			break;
	default:
		break;
	}
}

void idle(){
//repaint
	display();
}
void logics() {
	while (true)
	{
#ifdef __APPLE__
		usleep(20*1000);
#else
		Sleep(20);
#endif
		posnextConti();
		collisioncheck(player);
	}
}
int main(int argc, char **argv)
{
	win.width = 640;
	win.height = 480;
	win.title = (char *) "Menghindar? DIRI?!?!.";
	win.field_of_view_angle = 45;
	win.z_near = 1.0f;
	win.z_far = 500.0f;

	// initialize and run program
	glutInit(&argc, argv);                                      // GLUT initialization
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);  // Display Mode
	glutInitWindowSize(win.width, win.height);					// set window size
	glutCreateWindow(win.title);								// create Window
	glutDisplayFunc(display);									// register Display Function
	glutIdleFunc(idle);									// register Idle Function
	glutKeyboardFunc(keyboard);								// register Keyboard Handler
	glEnable(GLUT_MULTISAMPLE);								// Enable Multisampling
	initialize();
	w->connect();
	thread logic(logics);
	SoundPlayer sound((char *) "New.ogg");
	sound.Play();

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
