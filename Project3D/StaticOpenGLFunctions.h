#pragma once

#include <stdio.h>
#include "StaticSettings.h"
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

static void drawBarAdjuster(char *string);

static void drawText(int x, int y, char *string) {
	
	glRasterPos2f((GLfloat)x, (GLfloat)y);

	for (int i = 0; i < strlen(string); i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);


	
}

static void drawBarAdjuster(char *string) {
	// start x = 300, endx = 1095;
	int* currentValue = 0;

	if (string == "Music") {
		currentValue = &MusicVolume;
		GLfloat x = (GLfloat)(300 + 7.95 * *currentValue), y = GLfloat(600);
		glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x, y + 35);
		glVertex2f(x + 10, y + 35);
		glVertex2f(x + 10, y);
		glEnd();

	}
	else if (string == "Effects") {
		currentValue = &EffectVolume;
		GLfloat x = (GLfloat)(300 + 7.95 * *currentValue), y = (GLfloat)(600);
		glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x, y + 35);
		glVertex2f(x + 10, y + 35);
		glVertex2f(x + 10, y);
		glEnd();
	}

}
