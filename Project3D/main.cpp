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
<<<<<<< Updated upstream
#ifdef __APPLE__
=======
#include "Skybox.h"
#include <GL/glew.h>
#ifdef MAC_OSX
>>>>>>> Stashed changes
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <zconf.h>
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
ModelObject a = ModelObject((char *) "Models/lowPolyAirplane/lowPolyAirplane.obj");
struct Camera
{
	float posX = 15;
	float posY = -150; //-150 default
	float posZ = -5;
	float rotX = 0;
	float rotY = 0;
} camera;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(camera.posX, camera.posZ, camera.posY);

	//glRotatef(g_rotation, 0, 1, 0);
	g_rotation++;

	/*
	for (std::vector<shared_ptr<Character>>::iterator it = characters.begin(); it != characters.end(); it++) {
		Character temp = it._Ptr->get;
		temp.getModel().Draw();
	}
	*/

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1000, -10, -1000);
	glVertex3f(-1000, -10, 1000);
	glVertex3f(1000, -10, 1000);
	glVertex3f(1000, -10, -1000);
	glEnd();

	for (int i = 0; i < 10; i++)
	{

		glColor3f((GLfloat)i, (GLfloat)1.0f, (GLfloat)i);
		float x = enemy1[i][2];
		float y = enemy1[i][1];
		glPushMatrix();
<<<<<<< Updated upstream
		glTranslatef(y, 0 , x);
		glScalef(.3, .3, .3);
=======
		glTranslatef(y, 0, x);
>>>>>>> Stashed changes
		a.Draw();
		glPopMatrix();
	}
//	ModelObject("Models/cube.obj").Draw();

	player->Draw();

	glutSwapBuffers();

}

void initialize()
{
	create(10);
	w->connect();
	glDepthMask(GL_FALSE);
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

	//glBindVertexArray(skyboxVAO);
	Skybox box;
	box.loadskybox();
	glBindTexture(GL_TEXTURE_CUBE_MAP, box.getcubemapTexture());
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthMask(GL_TRUE);

	// Light 1
	GLfloat amb_light[] = { (GLfloat)0.1, (GLfloat)0.1, (GLfloat)0.1, (GLfloat)1.0 };
	GLfloat diffuse[] = { (GLfloat)0.6, (GLfloat)0.6, (GLfloat)0.6, (GLfloat)1 };
	GLfloat specular[] = { (GLfloat)0.7,(GLfloat) 0.7,(GLfloat) 0.3, (GLfloat)1 };

	//GLfloat mat_specular[] = { 0.1,0.1,0.1,1 };
	//GLfloat mat_shininess[] = { 50.0 };
	//GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	//glClearColor(0.0, 0.0, 0.0, 0.0);

	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);

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
<<<<<<< Updated upstream
	player = new Player(-10,0,130,1,1,1,new ModelObject("Models/lowPolyAirplane/lowPolyAirplane.obj"));
=======
	player = new Player(0, 0, 0, 1, 1, 1, new ModelObject("Models/sphere.obj"));
	player->getModelObject()->Draw();
>>>>>>> Stashed changes
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

void idle() {
	if (i == 60) {
		offset += w->leftRightMovement();

		i = 0;
	}
	i++;

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
	glEnable(GLUT_MULTISAMPLE);
	initialize();
	w->connect();
	thread logic(logics);
<<<<<<< Updated upstream
	SoundPlayer sound((char *) "New.ogg");
//	sound.Play();
=======
	SoundPlayer sound("New.ogg");
	//sound.Play();
>>>>>>> Stashed changes

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
