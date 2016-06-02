#include <math.h>
#include <cmath>
#include <string>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include "Player.h"
#include "enemy.h"
//#include "logic.h"

extern double enemy1[10][3];
extern enemy enemybuffer1[10];
bool done = false;
int widthEnemy;
ModelObject* o = new ModelObject("Models/lowPolyAirplane/lowPolyAirplane.obj");
void create(double width) {
	widthEnemy = width;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		done = false;
		while (done == false) {
			
			double random = ((rand() % 10 + 1) / 10.0) - 1;
			if (i == 0) {
				

					enemybuffer1[i] = enemy(random*40.0, 0 , i*20+10,1,1,1,o,random);
					done = true;

			}
			else {
				enemybuffer1[i] = enemy(random*40.0, 0, i * 20 + 10, 1, 1, 1, o, random);
				done = true;
			}
			
		}
	}
}
void createI(int i) {
	srand(time(NULL));
	Sleep(15);
	bool done = false;
	while (done == false) {
		double randomVal = ((rand() % 10 + 1) / 10.0) - 1;
		if (i == 9) {
				enemybuffer1[i] = enemy(randomVal*40.0, 0, enemybuffer1[0].getz() - 20, 1, 1, 1, o, randomVal);
				done = true;
		}
		else {
			
				enemybuffer1[i] = enemy(randomVal*40.0, 0, enemybuffer1[i+1].getz() - 20, 1, 1, 1, o, randomVal);
				done = true;

		}
		
	}
	}
void collisioncheck(Player *player) {
	for (int i = 0; i < 10; i++)
	{
		if (player->getCollisionBox()->intersect(enemybuffer1[i].getCollisionBox()) != 0) {
			std::cout << "1" << std::endl;
		}
	}
}
void posnextConti() {
	for (int i = 0; i < 10; i++)
	{
		enemybuffer1[i].move(0,0,1);
			if (enemybuffer1[i].getz() > 216) {
				createI(i);
			}
		
	
	}

}


