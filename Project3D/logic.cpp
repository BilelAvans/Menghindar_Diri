#include <math.h>
#include <cmath>
#include <string>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include "Player.h"
#include "enemy.h"
#include "logic.h"

#ifdef __APPLE__
#include <zconf.h>
#else
#include <windows.h>
#endif


double enemy1[10][3];
enemy enemybuffer1[10];
bool done = false;
float gameWidth = 30.0f;
int widthEnemy;
Node* o;
Node* op;
void create(double width) {
	widthEnemy = width;
	srand(rand());
	for (int i = 0; i < 20; i++)
	{
		done = false;
		while (done == false) {

			double random = ((rand() % 10 + 1) / 10.0) - 1;
			if (i == 0) {
				enemybuffer1[i] = enemy(random*gameWidth, 0, i * 20 - 200, 1, 1, 1, o, random, false);
				done = true;
			}
			else {
				enemybuffer1[i] = enemy(random*gameWidth, 0, i * 20 - 200, 1, 1, 1, o, random, false);
				done = true;
			}

		}
	}
}

void init() {
	o = new Node(new ObjModel("Models/lowPolyAirplane/lowPolyAirplane.obj"));
	op = new Node(new ObjModel("Models/lowPolyAirplane/lowPolyAirplaneP.obj"));
}

void createI(int i) {
	srand(rand()*rand());

#ifdef __APPLE__
	usleep(15 * 1000);
#else
	Sleep(15);
#endif

	bool done = false;
	while (done == false) {
		double random = ((rand() % 10 + 1) / 10.0) - 1;
		double randomP= (rand() % 20 + 1) - 1;
		if (i == 9) {
			if (randomP != 7) {
				enemybuffer1[i] = enemy(random*gameWidth, 0, enemybuffer1[0].getz() - 20, 1, 1, 1, o, random, false);
				done = true;
			} 
			else {
				enemybuffer1[i] = enemy(random*gameWidth, 0, enemybuffer1[0].getz() - 20, 1, 1, 1, op, random, true);
				done = true;
			}
		}
		else {
			if (randomP != 7) {
			enemybuffer1[i] = enemy(random*gameWidth, 0, enemybuffer1[i + 1].getz() - 20, 1, 1, 1, o, random, false);
			done = true;
			}
			else {
				enemybuffer1[i] = enemy(random*gameWidth, 0, enemybuffer1[i + 1].getz() - 20, 1, 1, 1, op, random, true);
				done = true;
			}
		}
	}
}

bool collisioncheck(Player *player) {
	if (player->isLit > 0)
	{
		player->isLit--;
	} else{ 
		player->score++;
		if (player->invince > 0) {
			player->invince--;
		}
		//cout << "score: " << player->score << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		
		if (player->getCollisionBox()->intersect(enemybuffer1[i].getCollisionBox()) != 0 && enemybuffer1[i].powerUp == -1 && player->isLit <= 0 && player->invince <=0) {
			player->isLit = 75;
			player->life--;

			cout << "shits lit yo" << endl;
			cout << "lives: " << player->life << endl;
			return true;
		}
		if (player->getCollisionBox()->intersect(enemybuffer1[i].getCollisionBox()) != 0 && enemybuffer1[i].powerUp != -1 && player->isLit <= 0) {
			player->invince = 150;
		}
	}
	return false;
}

void posnextConti() {
	for (int i = 0; i < 10; i++)
	{
		enemybuffer1[i].move(0, 0, 1);
		if (enemybuffer1[i].getz() > 216) {
			createI(i);
		}
	}
}


