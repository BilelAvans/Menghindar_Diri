#pragma once
#include "../irrKlang-1.5.0/64/include/irrKlang.h"

#include <iostream>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <string.h>

#include "irrKlang.h"
#include "StaticSettings.h"


// Put all music in /Sounds/ folder and use the filename.extention to load it up

class SoundPlayer {
	
	private:
		std::string filename;
		bool musicThreadjeRunning = false;
		// Our little music thread
		std::thread musicThreadje;

	public:
		void Load();
		void Play();
		void PlaySoundje();
		void PlaySoundInThread();
		void Pause();
		void Stop();
		void setVolume(float fVolume);
		int  getVolume();
		int  getTimeLength(); // in miliseconds!
		SoundPlayer(std::string filename);

		static SoundPlayer* ofThemeSong();

		SoundPlayer::~SoundPlayer() {
			musicThreadjeRunning = false;
			Sleep(1);
			if (musicThreadje.joinable())
				musicThreadje.detach();
		}


};