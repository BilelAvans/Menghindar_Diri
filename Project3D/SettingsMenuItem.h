#pragma once

#include "MenuItem.h"
#include "irrKlang.h"

class SettingsMenuItem : public MenuItem {

public:

	SettingsMenuItem(int idn, char* Textn, void(*doSomethingn)()) : MenuItem(idn, Textn, doSomethingn) {};
	SettingsMenuItem(int idn, char* Textn, void(*doSomethingn)(char* MenuType), char* funcargsn) : MenuItem(idn, Textn, doSomethingn, funcargsn) {};

	char* barTitle;

	void Fun();
	void IncrementSlider();
	void DecrementSlider();

	//void Fun() { }
	char* getInstanceTypeName() {
		return "SettingsMenuItem";
	}

	~SettingsMenuItem() { }
};