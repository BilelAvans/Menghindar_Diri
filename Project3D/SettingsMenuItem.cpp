#include "SettingsMenuItem.h"


void SettingsMenuItem::Fun() {
	//printf("here %s", this->Text);
	
	if (this->Text == "Music") {
		drawText(310, 650, "Music");
		drawBarAdjuster("Music");
	}
	else if (this->Text == "Effects") {
		drawText(310, 650, "Effects");
		drawBarAdjuster("Effects");
	}
	else if (this->Text == "Sensitivity") {
		drawText(310, 650, "Sensitivity");
		drawBarAdjuster("Sensitivity");
	}
}

void SettingsMenuItem::IncrementSlider() {
	if (this->Text == "Music") {
		incrementMusicVolume(1);
	}
	else if (this->Text == "Effects"){
		incrementEffectVolume(1);
	}
	else if (this->Text == "Sensitivity") {
		// ??
	}
}
void SettingsMenuItem::DecrementSlider() {
	if (this->Text == "Music") {
		incrementMusicVolume(-1);
	}
	else if (this->Text == "Effects") {
		incrementEffectVolume(-1);
	}
	else if (this->Text == "Sensitivity") {
		// ??
	}
}
