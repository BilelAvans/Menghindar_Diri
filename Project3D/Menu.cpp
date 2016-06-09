#include "stb_image.h"

#include <stdio.h>
#include "Menu.h"
#include "SettingsMenuItem.h"

bool barset = false;

Menu::Menu() {

}

void Menu::TraverseUp() {
	selectedIndex--;

	if (selectedIndex == -1)
		selectedIndex = menuItems.size() - 1;
}

void Menu::TraverseDown() {
	selectedIndex++;

	if (selectedIndex == menuItems.size())
		selectedIndex = 0;
}

void Menu::ResetToValue(int value) {
	selectedIndex = value;
}

std::vector<MenuItem*> Menu::getMenuItems() {
	return menuItems;
}

bool Menu::IsSelectedIndex(int value) {
	return value == selectedIndex;
}

void Menu::addMenuItem(MenuItem* item) {
	menuItems.push_back(item);
}

void Menu::setBackGround(char* source) {
	glEnable(GL_TEXTURE_2D);

	backgroundPixels = stbi_load(source, &wid, &hei, &bitdepth, STBI_rgb);
	
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);/*
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GLU_TESS_COMBINE);
	glTexEnvf(GL_TEXTURE_ENV, GLU_TESS_COMBINE, GL_INCR);*/

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, wid, hei, 0, GL_RGB, GL_UNSIGNED_BYTE, backgroundPixels);

	stbi_image_free(backgroundPixels);

}

void Menu::DrawBackGround() {
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);	glVertex3d(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3d(0, 720, 0);
	glTexCoord2f(1, 1); glVertex3d(1200, 720, 0);
	glTexCoord2f(1, 0); glVertex3d(1200, 0, 0);
	glEnd();
	
}

void Menu::DrawMenu(void(*func)(int, int, char*)) {
	int y = 650;

	// Textures uitzetten anders kunnen we bitmaps geen kleur geven blijkbaar
	glDisable(GL_TEXTURE_2D);
	// Alle menu items diaplyen
	for (MenuItem *item :this->getMenuItems()) {
		// Kleur aanpassen naar selectie
		if (this->IsSelectedIndex(item->id))
			glColor3f(0.0, 1.0, 0.0);
		else
			glColor3f(1.0, 0.0, 0.0);

		func(30, y, item->Text);
		// Volgende text komt eronder
		y -= 30;
	}

	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_TEXTURE_2D);
}


void Menu::activateCurrentItem() {
	//printf("Menu item id was %i", selectedIndex);
	try {
		if (menuItems.at(selectedIndex)->doSomething != NULL)
			menuItems.at(selectedIndex)->doSomething(menuItems.at(selectedIndex)->funcargs);
		else if (menuItems.at(selectedIndex)->doFunc != NULL)
			menuItems.at(selectedIndex)->doFunc();
	}
	catch (int i) {
	}

}

void Menu::drawBar(void) {
	////std::cout << "Drawing bar \n";
	////setBar();
	////glEnd();
	////glEnd();
	////glBegin(GL_TEXTURE_2D);
	////glEnd();

	////glBegin(GL_TEXTURE_2D);
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, texture2);
	////glBegin(GL_QUADS);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0, 0);	glVertex3d(0, 0, 0);
	//glTexCoord2f(0, 1); glVertex3d(0, 100, 0);
	//glTexCoord2f(1, 1); glVertex3d(800, 100, 0);
	//glTexCoord2f(1, 0); glVertex3d(800, 0, 0);
	////drawBar();
	//glEnd();


}

void Menu::Back() {
	if (goBack != nullptr)
		goBack("MainMenu");
}

MenuItem* Menu::getCurrentItem() {

	return menuItems.at(selectedIndex);
}

// Static builders
Menu* Menu::ofMainMenu(void(*func1)(char* MenuType), void(*toGame)()) {
	Menu *menu = new Menu();
	// Add menuitems
	menu->addMenuItem(new MenuItem( 0, "Play Game", toGame ));
	menu->addMenuItem(new MenuItem( 1, "Theme", func1, "ThemeMenu" ));
	menu->addMenuItem(new MenuItem( 2, "Settings", func1, "SettingsMenu" ));
	menu->addMenuItem(new MenuItem( 3, "Scoreboard", func1, "ScoreMenu" ));
	menu->addMenuItem(new MenuItem( 4, "Help", func1, "HelpMenu" ));

	menu->setBackGround("Backgrounds/MainMenuBlankPage.png");

	return menu;

}

Menu* Menu::ofHelpMenu(void(*goback)(char* MenuType), void(*func0)(), void(*func1)(), void(*func2)()) {
	Menu *menu = new Menu();

	menu->addMenuItem(new MenuItem{ 0, "Objects", func0 });
	menu->addMenuItem(new MenuItem{ 1, "Powers Ups", func1});
	menu->addMenuItem(new MenuItem{ 2, "Extra", func2 });

	menu->setBackGround("Backgrounds/HelpMenuBlankPage.png");
	menu->goBack = goback;

	return menu;
}

Menu* Menu::ofSettingsMenu(void(*goback)(char* MenuType), void(*func0)(), void(*func1)(), void(*func2)()) {
	Menu *menu = new Menu();

	menu->addMenuItem(new SettingsMenuItem{ 0, "Music", func0 });
	menu->addMenuItem(new SettingsMenuItem{ 1, "Effects", func1 });
	menu->addMenuItem(new SettingsMenuItem{ 2, "Sensitivity", func2});

	menu->setBackGround("Backgrounds/SettingsMenuBlankPage.png");
	menu->goBack = goback;

	
	return menu;
}

Menu* Menu::ofThemeMenu(void(*goback)(char* MenuType), void(*func0)(), void(*func1)(), void(*func2)()) {
	Menu *menu = new Menu();

	menu->addMenuItem(new MenuItem{ 0, "Map", func0 });
	menu->addMenuItem(new MenuItem{ 1, "Player", func1 });
	menu->addMenuItem(new MenuItem{ 2, "Enemy", func2 });

	menu->setBackGround("Backgrounds/ThemeMenuBlankPage.png");
	menu->goBack = goback;

	return menu;
}
