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

class Game {

private:
	GameController *w;
	void(*backspaceFunc)();
	void(*endFunc)(char*);

	float g_rotation;
	glutWindow win;
	int offset = 0;
	int i = 0;

	Player* player;
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

	static Game game;

	static void displayWrapper();
	static void keyboardWrapper(unsigned char c, int a, int b);
	static void idleWrapper();
	static void setInstance(Game game);
	static void logicsWrapper();

	virtual void display(void);

	void mousePassiveMotion(int x, int y);

	void initialize(void);

	virtual void keyboard(unsigned char key, int x, int y);
	virtual void logics(void);
	virtual void idle(void);
	void Run(Game g);
	void Stop();

	~Game() { std::cout << "Cleaning uo Game"; }

};