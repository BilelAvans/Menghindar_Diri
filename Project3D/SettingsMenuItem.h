#pragma once

#include "MenuItem.h"
#ifdef __APPLE__
#include "../irrKlang-1.5.0/64/include/irrKlang.h"
#else
#include "irrKlang.h"
#endif

class SettingsMenuItem : public MenuItem {

public:

	SettingsMenuItem(int idn, char* Textn, void(*doSomethingn)()) : MenuItem(idn, Textn, doSomethingn) {};
	SettingsMenuItem(int idn, char* Textn, void(*doSomethingn)(char* MenuType), char* funcargsn) : MenuItem(idn, Textn, doSomethingn, funcargsn) {};

	char* barTitle;

	void Fun();
	void IncrementSlider();
	void DecrementSlider();
	char* getInstanceTypeName() {
		return "SettingsMenuItem";
	}

	~SettingsMenuItem() { }
};