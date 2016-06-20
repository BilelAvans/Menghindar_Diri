#include "SoundPlayer.h"


using namespace irrklang;
using namespace std;

bool musicThreadjeRunning = false;
// Our little music thread
std::thread musicThreadje;
irrklang::ISoundEngine* engine;
irrklang::ISoundSource* soundSource;

SoundPlayer::SoundPlayer(std::string filename) {
	// Load our music (after placement in /Sounds/ folder)
	this->filename = filename;

	Load();	
}

void SoundPlayer::Load() {
	engine = createIrrKlangDevice();
	// Read out sound info (Source, Length, Format, ...)
	soundSource = engine->addSoundSourceFromFile(filename.c_str());

}

void SoundPlayer::Play() {
	// Grab volume from settings
	engine->play2D(filename.c_str(), false);
}

void SoundPlayer::Pause() {
	engine->setAllSoundsPaused();
}

void SoundPlayer::Stop() {
	musicThreadjeRunning = false;
	engine->stopAllSounds();
}

void SoundPlayer::setVolume(float fVolume) {
	engine->setSoundVolume((float)(fVolume / 100));
}

int SoundPlayer::getVolume() {
	return engine->getSoundVolume();
}

int SoundPlayer::getTimeLength() {
	return soundSource->getPlayLength();
}

void SoundPlayer::PlaySoundInThread() {
	if (!musicThreadjeRunning) {
		musicThreadjeRunning = true;

		Play();
		// Add time in seconds to our endtime variable
		time_t endTime = time(0) + getTimeLength() / 1000;
		//if (getTimeLength() / 1000 < 1)
			//Sleep(getTimeLength());

		while (difftime(endTime, time(0)) > 0 && musicThreadjeRunning) {
		}
		
		Stop();
		musicThreadjeRunning = false;
		musicThreadje.detach();
	}
}

void SoundPlayer::PlaySoundje() {
	if (musicThreadjeRunning) {
		musicThreadjeRunning = false;
		Sleep(1);
	}

	if (!musicThreadje.joinable()) {
		musicThreadje = std::thread(&SoundPlayer::PlaySoundInThread, this);
	}
	
}

// Create a soundplayer with one of the theme songs
SoundPlayer* SoundPlayer::ofThemeSong() {
	
	std::string str = "Sounds/New";
	str += (char)(rand() % 2 + 48);
	str.append(".ogg");

	return new SoundPlayer(str);
}