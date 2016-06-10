#pragma once


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <thread>
#include "Character.h"
#include "Player.h"
#include "ModelObject.h"


#include "Controls/GameController.h"
#include "SoundPlayer.h"
#include <thread>
#include "Skybox.h"
#include "StaticSettings.h"

#ifdef __APPLE__
#include "../irrKlang-1.5.0/64/include/irrKlang.h"
#include "../irrKlang-1.5.0/64/include/ik_ISound.h"
#else
#include "irrKlang.h"
#include "ik_ISound.h"
#endif

#include "logic.h"

extern void Run();
extern void(*backspaceFunc)();
void Stop();

class Game {

private:

	void(*endFunc)(char*);

	float g_rotation;

	int offset = 0;
	int i = 0;
	void(*backspaceFunc)();

public:
	Game(void(*backspacefunc)(), void(*endfunc)(char*), GameController *gc);
	~Game();
};