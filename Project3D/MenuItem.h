#pragma once
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

#include "StaticOpenGLFunctions.h"

class MenuItem {

public:
	int id;						// Nummertje
	char* Text;					// Titel

	// Functie bij indrukken 'Enter'
	void(*doFunc)();
	void(*doSomething)(char* MenuType);	

	char* funcargs;

	MenuItem(int idn, char* Textn, void(*doSomethingn)()) {
		id = idn;
		Text = Textn;
		doFunc = doSomethingn;
	}

	MenuItem(int idn, char* Textn, void(*doSomethingn)(char* MenuType), char* funcargsn) {
		id = idn;
		Text = Textn;
		doSomething = doSomethingn;
		funcargs = funcargsn;
	}

	virtual void Fun() { }
	virtual char* getInstanceTypeName() {
		return "MenuItem";
	}

	virtual ~MenuItem() { std::cout << "Cleaning uo menu item"; }
};
//
//class SettingsMenuItem: public MenuItem {
//
//public:
//	SettingsMenuItem(int idn, char* Textn, void(*doSomethingn)()) : MenuItem(idn, Textn, doSomethingn) { };
//	SettingsMenuItem(MenuItem* item) : MenuItem(*item) { };
//
//	char* scrollBarText;
//
//	
//	//void Run();
//
//};

