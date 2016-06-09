#pragma once
#include "../irrKlang-1.5.0/64/include/irrKlang.h"

#include <iostream>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <time.h>

#include "irrKlang.h"
#include "StaticSettings.h"


// Put all music in /Sounds/ folder and use the filename.extention to load it up

class SoundPlayer {
	
	// Our 'real' player
	char* filename;
	void Load();
	void PlaySoundInThread();
	bool musicThreadjeRunning = false;
	// Our little music thread
	std::thread musicThreadje;
	irrklang::ISoundEngine* engine;
	irrklang::ISoundSource* soundSource;

	public:

		void Play();
		void PlaySoundje();
		void Pause();
		void Stop();
		void setVolume(float fVolume);
		int  getVolume();
		int  getTimeLength(); // in miliseconds!
		SoundPlayer(char* filenameArgs);
		~SoundPlayer();


};