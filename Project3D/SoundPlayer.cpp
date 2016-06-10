#include <iostream>
#include "SoundPlayer.h"
#include "StaticSettings.h"

using namespace irrklang;
using namespace std;
char* filename;
ISoundEngine* engine;
SoundPlayer::SoundPlayer(char* filename) {
	this->filename = (char *) "Sounds/New.ogg";	
	Load();
}

void SoundPlayer::Load() {
	engine = createIrrKlangDevice();
}

void SoundPlayer::Play() {
	setVolume((float)MusicVolume / float(100));
	engine->play2D(filename, true);
}

void SoundPlayer::Pause() {
	engine->setAllSoundsPaused();
}

void SoundPlayer::Stop() {
	engine->stopAllSounds();
}

void SoundPlayer::setVolume(float fVolume) {
	engine->setSoundVolume(fVolume);
}

int SoundPlayer::getVolume() {
	return engine->getSoundVolume();
}

SoundPlayer::~SoundPlayer() {
	engine->drop();
}