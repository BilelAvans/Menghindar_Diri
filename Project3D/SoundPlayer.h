#pragma once
#include "../irrKlang-1.5.0/64/include/irrKlang.h"

// Put all music in /Sounds/ folder and use the filename.extention to load it up

class SoundPlayer {
	
	private:
		// Our 'real' player
		char* filename;
		void Load();

	public:
		void Play();
		void Pause();
		void Stop();
		SoundPlayer(char* filename);
		~SoundPlayer();

};