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

//Player *player;

Game *game;

void comeback();

void(*backspaceFunc)() = comeback;


int window_width = 1200, window_height = 720;
Menu *mMenu;

GameController *gw = GameController::getInstance();

void output(GLfloat x, GLfloat y, char *text)
{
	char *p;

	glPushMatrix();
	glTranslatef(x, y, 0);
	for (p = text; *p; p++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}


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
//	glutLeaveFullScreen();
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(50, 50);

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeysFunc);
}

void setMenu(char* MenuType);

void comeback() {
	resetMenu();

	setMenu("MainMenu");
}

void Keys(unsigned char c, int a, int b) {
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
	glutKeyboardFunc(Keys);
	setStaticSettings(50, 30, 0); // Settings (Music Volumme, Effects Volume, Wii board sensitivity)
	//printf("Member is %i", MusicVolume);
	//w->connect();

	// Start in Main Menu
	setMenu("MainMenu");
	// Run openGL
	glutMainLoop();

	return 0;
}
