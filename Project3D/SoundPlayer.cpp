#include "SoundPlayer.h"


using namespace irrklang;
using namespace std;



SoundPlayer::SoundPlayer(char* filenameArgs) {
	// Load our music (after placement in /Sounds/ folder)

	/* ??????
	this->filename = (char *) "Sounds/New.ogg";
	*/
	this->filename = filenameArgs;


	Load();
	//printf("%g", difftime(clock2, clock1));
	// Read out sound info (Source, Length, Format, ...)
	soundSource = engine->addSoundSourceFromFile(filenameArgs);
}

void SoundPlayer::Load() {
	engine = createIrrKlangDevice();
}

void SoundPlayer::Play() {
	// Grab volume from settings
	engine->play2D(filename, false);
}

void SoundPlayer::Pause() {
	engine->setAllSoundsPaused();
}

void SoundPlayer::Stop() {
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
		printf("looool \n");
		Play();
		// Create our end time
		time_t endTime = time(0) + getTimeLength() / 1000;
		for (double waitingtime = getTimeLength(); difftime(endTime, time(0)) > 0 && musicThreadjeRunning;) { }
		//Stop();
		printf("ddsdssd \n");
		musicThreadjeRunning = false;
		musicThreadje.detach();
	}
}

void SoundPlayer::PlaySoundje() {
	if (musicThreadjeRunning) {
		musicThreadjeRunning = false;
	}

	if (!musicThreadje.joinable()) {
		musicThreadje = std::thread(&SoundPlayer::PlaySoundInThread, this);
		musicThreadjeRunning = false;
	}
	
}