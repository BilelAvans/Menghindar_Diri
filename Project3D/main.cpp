#define STB_IMAGE_IMPLEMENTATION

#include <windows.h>
#include <string.h>
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
#include <fstream>
#include <fileapi.h>
#include <stdio.h>

#include "Game.h"
#include "Menu.h"

void toGame();

int window_width = 1200, window_height = 720;
Menu mMenu;

void Idle() {
	glutPostRedisplay();
}

void drawText(int x, int y, char *string)
{
	glRasterPos2f(x, y);

	for (int i = 0; i < strlen(string); i++) 
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
	
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
	mMenu.DrawBackGround();
	mMenu.DrawMenu(drawText);

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
		case 8: mMenu.Back();
			break;
		// 'W'
		case 119: mMenu.TraverseUp(); 
			break;
		// 'S'
		case 115: mMenu.TraverseDown(); 
			break;
		case 13: mMenu.activateCurrentItem();
			break;
	}
	
}

void setMenu() {

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

void toGame() {
	Game game = Game();
	game.Run();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GL_DOUBLE | GL_RGB);
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
	
	// Load menu test
	setMenu("MainMenu");
	//printf("Found error: %s", glGetError());
	//glEnable(GL_TEXTURE_2D);
	//Game game = Game();
	//game.Run(argc, argv);

	glutMainLoop();
	
	return 0;
}
