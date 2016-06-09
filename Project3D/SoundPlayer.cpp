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

int SoundPlayer::getTimeLength() {
	return soundSource->getPlayLength();
}

SoundPlayer::~SoundPlayer() {
	engine->drop();	
}

void SoundPlayer::PlaySoundInThread() {
	if (!musicThreadjeRunning) {
		musicThreadjeRunning = true;

		Play();
		// Create our end time
		time_t endTime = time(0) + getTimeLength() / 1000;
		for (double waitingtime = getTimeLength(); difftime(endTime, time(0)) > 0 && musicThreadjeRunning;) { }

		musicThreadjeRunning = false;
		Stop();

		musicThreadje.detach();
	}


}

void SoundPlayer::PlaySoundje() {
	if (musicThreadjeRunning)
		musicThreadjeRunning = false;

	Sleep(1);

	musicThreadje = std::thread(&SoundPlayer::PlaySoundInThread, this);
}