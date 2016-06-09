#pragma once


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include "Character.h"
#include "Player.h"
#include "ModelObject.h"


#include "Controls/GameController.h"
#include "SoundPlayer.h"
#include <thread>
#include "Skybox.h"
#include "StaticSettings.h"
#include "irrKlang.h"
#include "ik_ISound.h"
#include "logic.h"

extern void Run();


//#include "SoundPlayer.h"
//#include <thread>
//#include "Skybox.h"
//#ifdef __APPLE__
//#include <OpenGL/OpenGL.h>
//#include <GLUT/glut.h>
//#include <zconf.h>
//#include "Controls/keyboard/KeyboardController.h"
//#include "Objects/node/Node.h"

using namespace irrklang;

#define KEY_ESCAPE 27

using namespace std;

extern void(*backspaceFunc)();

void Stop();

class Game {

private:

	void(*endFunc)(char*);

	float g_rotation;

	int offset = 0;
	int i = 0;
	void(*backspaceFunc)();

	
	Node *a;
	//= ModelObject((char *) "Models/lowPolyAirplane/lowPolyAirplane.obj");
	struct Camera
	{
		float posX = 10;
		float posY = -170; //-150 default
		float posZ = -10;
		float rotX = 0;
		float rotY = 0;
	} camera;

	Node *node;

public:
	
	Game(void);
	Game(void(*backspacefunc)(), void(*endfunc)(char*), GameController *gc);
	
	void mousePassiveMotion(int x, int y);

	//void initialize(void);

	//void keyboard(unsigned char key, int x, int y);
	//void logics(void);
	//void idle(void);
	//void display(void);
	//void Run();
	//void Stop();

	~Game() { std::cout << "Cleaning up Game"; }

};