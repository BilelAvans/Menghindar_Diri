#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>

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

#include "MenuItem.h"
#include "highscore\Highscore.h"


class Menu {

	private:
		// Menu items
		std::vector<MenuItem*> menuItems = std::vector<MenuItem*>();
		// Geselecteerde menu item (positie in vector)
		int selectedIndex = 0;
		// Plaatje/Texture (OpenGL)
		int wid, hei, bitdepth;
		// Data uit stbi_load
		unsigned char* backgroundPixels;
		// TextureID in OpenGL
		GLuint texture1;
		// Backspace functie
		void(*goBack)(char* MenuType);
		char* goBackArguments;

	public:
		Menu();
		// Menu tekenen (Open-Gl Code inside)
		void DrawMenu(void(*func)(int, int, char*));
		void DrawBackGround();
		// source als src path naar bestand (ex: "Backgrounds/Plaatje.png")
		void setBackGround(char* source);

		std::vector<MenuItem*> getMenuItems(void);
		MenuItem* getCurrentItem();
		// Item toevoegen
		void addMenuItem(MenuItem* item);
		// Menu-scroll functies
		void TraverseDown(void);
		void TraverseUp(void);
		// Naar bepaalde positie gaan
		void ResetToValue(int value);
		bool IsSelectedIndex(int value);
		// Functie achter de selectie uitvoeren
		void activateCurrentItem(void);
		void drawBar(void);

		// Backspace implementatie (Naar welke menu gaan we terug?)
		void Back(void);

		// Pre-built menu's.
		static Menu* ofMainMenu(void(*func1)(char* MenuType), void(*func)(), bool gamewaslaunched);
		static Menu* ofHelpMenu(void(*goback)(char* MenuType), void(*func0)(), void(*func1)(), void(*func2)(), bool gamewaslaunched);
		static Menu* ofSettingsMenu(void(*goback)(char* MenuType), void(*func0)(), void(*func1)(), void(*func2)(), bool gamewaslaunched);
		static Menu* ofThemeMenu(void(*goback)(char* MenuType), void(*func0)(), void(*func1)(), void(*func2)(), bool gamewaslaunched);
		static Menu* ofHighScoreMenu(void(*goback)(char* MenuType), void(*func0)(), Highscore scores, bool gamewaslaunched);
};