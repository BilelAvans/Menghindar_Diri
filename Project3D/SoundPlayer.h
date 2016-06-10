#pragma once
#include "../irrKlang-1.5.0/64/include/irrKlang.h"


class SoundPlayer {
	
	private:
		char* filename;
		void Load();

	public:
		void Play();
		void Pause();
		void Stop();
		void setVolume(float fVolume);
		int  getVolume();
		SoundPlayer(char* filename);
		~SoundPlayer();

};