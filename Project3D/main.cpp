#define STB_IMAGE_IMPLEMENTATION

#ifdef __APPLE__
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

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "Game.h"
#include "Controls/GameController.h"
#include "Menu.h"
#include "SettingsMenuItem.h"
#include "StaticOpenGLFunctions.h"
#include "StaticSettings.h"

int MusicVolume = 0;
int EffectVolume = 0;
int WiiBoadSensitivity = 0;

Game *game;

void comeback();

void(*backspaceFunc)() = comeback;


int window_width = 1200, window_height = 720;
Menu *mMenu;

GameController *gw = GameController::getInstance();


void Idle() {
	glutPostRedisplay();
}


void Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, window_width, 0, window_height, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Draw Menu
	mMenu->DrawBackGround();
	mMenu->DrawMenu(drawText);

	mMenu->getCurrentItem()->Fun();
	//std::auto_ptr<MenuItem> item = std::auto_ptr<MenuItem>(mMenu->getCurrentItem());

	glutSwapBuffers();
}

void Reshape(int w, int h) {
	glViewport(0, 0, window_width, window_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
}

void KeysFunc(unsigned char c, int a, int b) {
	switch (c) {
		// Backspace
	case 8: mMenu->Back();
		break;
		// 'W'
	case 119: mMenu->TraverseUp();
		break;
		// 'S'
	case 115: mMenu->TraverseDown();
		break;
	case 13: mMenu->activateCurrentItem();
		break;
	}
		switch (c) {
		case 'a':
			if (mMenu->getCurrentItem()->getInstanceTypeName() == "SettingsMenuItem") {
				SettingsMenuItem *it = (SettingsMenuItem*)mMenu->getCurrentItem();
				it->DecrementSlider();
			}
			break;
		case 'd':
			if (mMenu->getCurrentItem()->getInstanceTypeName() == "SettingsMenuItem") {
				SettingsMenuItem *it = (SettingsMenuItem*)mMenu->getCurrentItem();
				it->IncrementSlider();
			}
			break;
		}

}

void resetMenu() {
	glutLeaveFullScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(50, 50);

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeysFunc);

	//delete &game;

}

void setMenu(char* MenuType);

void comeback() {
	resetMenu();
	
	setMenu("MainMenu");
}
// Dummy function
void setMenu() {

}

void toGame() {
	// Create a game
	game = new Game(&comeback, &setMenu, gw);
	// Start
	Run();
}

void setMenu(char *MenuType) {
	if (MenuType == "MainMenu")
		mMenu = Menu::ofMainMenu(&setMenu, &toGame);
	if (MenuType == "ThemeMenu")
		mMenu = Menu::ofThemeMenu(&setMenu, &setMenu, &setMenu, &setMenu);
	if (MenuType == "SettingsMenu")
		mMenu = Menu::ofSettingsMenu(&setMenu, &setMenu, &setMenu, &setMenu);
	if (MenuType == "HelpMenu")
		mMenu = Menu::ofHelpMenu(&setMenu, &setMenu, &setMenu, &setMenu);

}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Glut");
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeysFunc);
	setStaticSettings(50, 30, 0); // Settings (Music Volumme, Effects Volume, Wii board sensitivity)
	//printf("Member is %i", MusicVolume);
	//w->connect();

	// Start in Main Menu
	setMenu("MainMenu");
	// Run openGL
	glutMainLoop();

	return 0;
}


//#include <iostream>
//#include <fstream>
//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//#include <sstream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <cmath>
//#include <memory>
//#include "Character.h"
//#include "Player.h"
//#include "ModelObject.h"
//#include "Controls/GameController.h"
//#include "logic.h"
//#include "SoundPlayer.h"
//#include <thread>
//#include "Skybox.h"
//#ifdef __APPLE__
//#include <OpenGL/OpenGL.h>
//#include <GLUT/glut.h>
//#include <zconf.h>
//#include "Controls/keyboard/KeyboardController.h"
//#include "Objects/node/Node.h"
//
//#else
//#include <GL/freeglut.h>
//#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include "Controls/wiimote/wiimote.h"
//#endif
//
//#define KEY_ESCAPE 27
//
//using namespace std;
//
//// The objects we will be drawing
////std::vector<std::shared_ptr<Character>> characters;
//
//float g_rotation;
//glutWindow win;
//GameController *w = GameController::getInstance();
//int offset = 0;
//int i = 0;
//
//Player* player;
//
//void collisionTest() {
//	CollisionBox* vagina = new CollisionBox(0, 0, 0, 2, 2, 2);
//	CollisionBox* lul = new CollisionBox(2, 2, 2, 2, 2, 2);
//	if (lul->intersect(vagina))
//	{
//		printf("ja hoor hij zit erin");
//	}
//}
//Node *a;
////= ModelObject((char *) "Models/lowPolyAirplane/lowPolyAirplane.obj");
//struct Camera
//{
//	float posX = 10;
//	float posY = -170; //-150 default
//	float posZ = -10;
//	float rotX = 0;
//	float rotY = 0;
//} camera;
//
//Node *node;
//
//void display()
//{
//
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//
//
//	//skybox
//	glPushMatrix();
//	glRotatef(180, 1, 0, 0);
//	drawSkybox(400.0);
//	glPopMatrix();
//
//	glTranslatef(camera.posX, camera.posZ, camera.posY);
//
//
//	//glRotatef(g_rotation, 0, 1, 0);
//	g_rotation++;
//	glRotatef(camera.rotX, 1, 0, 0);
//	glRotatef(camera.rotY, 0, 1, 0);
//	/*
//	for (std::vector<shared_ptr<Character>>::iterator it = characters.begin(); it != characters.end(); it++) {
//		Character temp = it._Ptr->get;
//		temp.getModel().Draw();
//	}
//	*/
//
//	for (int i = 0; i < 10; i++)
//	{
//
////		glColor3f((GLfloat)i, (GLfloat)1.0f, (GLfloat)i);
//		glPushMatrix();
//		enemybuffer1[i].Draw();
//		glPopMatrix();
//	}
////	ModelObject("Models/cube.obj").Draw();
//
//
//	player->Draw();
//
//	node->draw();
//	glutSwapBuffers();
//	
//}
//
//void mousePassiveMotion(int x, int y)
//{
////	int dx = x - win.width / 2;
////	int dy = y - win.height / 2;
////	if ((dx != 0 || dy != 0) && abs(dx) < 400 && abs(dy) < 400)
////	{
////		camera.rotY += dx / 10.0f;
////		camera.rotX += dy / 10.0f;
////		glutWarpPointer(win.width / 2, win.height / 2);
////	}
//}
//
//void initialize()
//{
//	init();
//	create(10);
//	w->connect();
//	glMatrixMode(GL_PROJECTION);
//	glViewport(0, 0, win.width, win.height);
//	GLfloat aspect = (GLfloat)win.width / win.height;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(win.field_of_view_angle, aspect, win.z_near, win.z_far);
//	glMatrixMode(GL_MODELVIEW);
//	//glShadeModel(GL_SMOOTH);
//	glClearColor(0.0f, 0.1f, 0.0f, 0.5f);
//	glClearDepth(1.0f);
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LEQUAL);
//	glEnable(GL_TEXTURE_2D);
//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST);
//	glutWarpPointer(win.width/2,win.height/2);
//
//	node = new Node(new ObjModel("Models/bloemetje/PrimroseP.obj"));
//	a = new Node(new ObjModel("Models/bloemetje/PrimroseP.obj"));
//
//
//	// Light 1
//	GLfloat amb_light[] = { (GLfloat)0.1, (GLfloat)0.1, (GLfloat)0.1, (GLfloat)1.0 };
//	GLfloat diffuse[] = { (GLfloat)0.6, (GLfloat)0.6, (GLfloat)0.6, (GLfloat)1 };
//	GLfloat specular[] = { (GLfloat)0.7,(GLfloat) 0.7,(GLfloat) 0.3, (GLfloat)1 };
//
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb_light);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
//	glEnable(GL_LIGHT0);
//	
//	glEnable(GL_COLOR_MATERIAL);
//	glShadeModel(GL_SMOOTH);
//	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
//	glDepthFunc(GL_LEQUAL);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	player = new Player(-10,0,130,1,1,1,new Node(new ObjModel("Models/lowPolyAirplane/lowPolyAirplane.obj")));
////	player = new Player(-10,0,130,1,1,1,new Node(new ObjModel("Models/bloemetje/PrimroseP.obj")));
//
//	initSkybox();
//	//player = new Player(-10,0,130,1,1,1,new ModelObject("Models/lowPolyAirplane/lowPolyAirplane.obj"));
//
//
//	//full screen
//	glutFullScreen();
//}
//
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key) {
//	case KEY_ESCAPE:
//		exit(0);
//		break;
//	case 'a':
////		camera.posX++;
//			player->move(-1, 0, 0);
//		break;
//	case 'd':
////		camera.posX--;
//			player->move(1, 0, 0);
//			break;
//	default:
//		break;
//	}
//}
//
//void idle(){
////repaint
//	display();
//}
//void logics() {
//	while (true)
//	{
//#ifdef __APPLE__
//		usleep(20*1000);
//#else
//		Sleep(20);
//#endif
//		posnextConti();
//		collisioncheck(player);
//	}
//}
//int main(int argc, char **argv)
//{
//	win.width = 640;
//	win.height = 480;
//	win.title = (char *) "Menghindar? DIRI?!?!.";
//	win.field_of_view_angle = 45;
//	win.z_near = 1.0f;
//	win.z_far = 500.0f;
//
//	// initialize and run program
//	glutInit(&argc, argv);                                      // GLUT initialization
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);  // Display Mode
//	glutInitWindowSize(win.width, win.height);					// set window size
//	glutCreateWindow(win.title);								// create Window
//	glutDisplayFunc(display);									// register Display Function
//	glutIdleFunc(idle);									// register Idle Function
//	glutKeyboardFunc(keyboard);								// register Keyboard Handler
//	glEnable(GLUT_MULTISAMPLE);								// Enable Multisampling
//	initialize();
//	w->connect();
//	thread logic(logics);
//	SoundPlayer sound((char *) "New.ogg");
//	sound.Play();
//
//	// Load objects
//	//ModelObject ob = ModelObject("Models/sphere.obj");
//	//ob.Move();
//	//ob.Release();
//	//blenderObjects.push_back(ob);
//	//std::shared_ptr<Player> player = make_shared<Player>(Player("Bilel"));
//	
//	//characters.emplace_back(player);
//
//	glutMainLoop();												// run GLUT mainloop
//	return 0;
//}
