#pragma once

extern int MusicVolume;
extern int EffectVolume;
extern int WiiBoadSensitivity;


static void setStaticSettings(int mv, int eff, int sen) {
	MusicVolume = mv, EffectVolume = eff, WiiBoadSensitivity = sen;
}

static void incrementMusicVolume(int amount) {
	MusicVolume += amount;

	if (MusicVolume < 0)
		MusicVolume = 0;

	if (MusicVolume > 100)
		MusicVolume = 100;
}

static void incrementEffectVolume(int amount) {
	EffectVolume += amount;

	if (EffectVolume < 0)
		EffectVolume = 0;

	if (EffectVolume > 100)
		EffectVolume = 100;
}

static void incrementSensitivity(int amount) {
	WiiBoadSensitivity += amount;

	if (WiiBoadSensitivity < 0)
		WiiBoadSensitivity = 0;

	if (WiiBoadSensitivity > 100)
		WiiBoadSensitivity = 100;
}