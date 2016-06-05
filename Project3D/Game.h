#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>
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

#define KEY_ESCAPE 27

using namespace std;

class Game {

public:
	Game(void);
	static Game game;

	static void displayWrapper();
	static void keyboardWrapper(unsigned char c, int a, int b);
	static void idleWrapper();
	static void setInstance(Game game);
	static void logicsWrapper();

	// The objects we will be drawing
	//std::vector<std::shared_ptr<Character>> characters;

	float g_rotation;
	glutWindow win;
	GameController *w = GameController::getInstance();
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

	virtual void display(void);

	void mousePassiveMotion(int x, int y);

	void initialize(void);


	virtual void keyboard(unsigned char key, int x, int y);
	virtual void logics(void);
	virtual void idle(void);
	void Run();

};