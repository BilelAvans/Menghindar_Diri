#include <iostream>
#include "SoundPlayer.h"

using namespace irrklang;
using namespace std;

char* filename;
ISoundEngine* engine;

SoundPlayer::SoundPlayer(char* filename) {
	// Load our music (after placement in /Sounds/ folder)
	//char* tempName = "Sounds/";
	//this->filename = new char[sizeof(filename) / sizeof(char) + 5 * sizeof(char)];
//	strcpy(this->filename, 20, tempName);
//	strcat(this->filename, 20, filename);

	this->filename = (char *) "Sounds/New.ogg";
	Load();
}

void SoundPlayer::Load() {
	engine = createIrrKlangDevice();
}

void SoundPlayer::Play() {
	engine->play2D(filename, true);
}

void SoundPlayer::Pause() {
	engine->setAllSoundsPaused();
}

void SoundPlayer::Stop() {
	engine->stopAllSounds();
}

SoundPlayer::~SoundPlayer() {
	engine->drop();
}