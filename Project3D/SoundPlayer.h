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
	
	private:
		char* filename;

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
		SoundPlayer(char* filename);

		//sSoundPlayer::~SoundPlayer();


};