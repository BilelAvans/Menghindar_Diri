#pragma once

#include "MenuItem.h"
#ifdef __APPLE__
#include "../irrKlang-1.5.0/64/include/irrKlang.h"
#else
#include "irrKlang.h"
#endif

#include "highscore\Highscore.h"

class HighscoreMenuItem : public MenuItem {

private:
	Highscore hScore;
public:
	HighscoreMenuItem(int idn, char* Textn, void(*doSomethingn)(), Highscore scores) : MenuItem(idn, Textn, doSomethingn) { hScore = scores;  };
	HighscoreMenuItem(int idn, char* Textn, void(*doSomethingn)(char* MenuType), char* funcargsn) : MenuItem(idn, Textn, doSomethingn, funcargsn) {};

	char* barTitle;

	void Fun();
	void IncrementSlider();
	void DecrementSlider();
	char* getInstanceTypeName() {
		return "SettingsMenuItem";
	}

	~HighscoreMenuItem() { }
};