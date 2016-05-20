#include <math.h>
#include <cmath>
#include <string>
#include <time.h>
#include <cstdlib>
//#include "logic.h"

extern double enemy1[10][3];
extern double enemybuffer1[10][3];
bool done = false;
double randomVal;
int widthEnemy;
void create(double width) {
	widthEnemy = width;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		done = false;
		while (done == false) {
			
			double random = ((rand() % 10 + 1) / 10.0) - 1;
			if (i == 0) {
				if (enemy1[i - 1][1] - random < 10 &&  enemy1[i - 1][1] - random>-10) {
					enemy1[i][0] = 0;
					enemy1[i][1] = random*40.0;
					enemy1[i][2] = i*20 + 10;
					done = true;
				}
			}
			else {
				enemy1[i][0] = 0;
				enemy1[i][1] = random*40.0;
				enemy1[i][2] = i*20 + 10;
				done = true;
			}
			
		}
	}
}
void createBuffer() {
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		done = false;
		while (done == false) {

			double random = ((rand() % 10 + 1) / 10.0) - 1;
			if (i == 0) {
				if (enemy1[i - 1][1] - random < 10 && enemy1[i - 1][1] - random>-10) {
					enemy1[i][0] = 0;
					enemy1[i][1] = random*20.0;
					enemy1[i][2] = i * 20 + 10;
					done = true;
				}
			}
			else {
				enemy1[i][0] = 0;
				enemy1[i][1] = random*20.0;
				enemy1[i][2] = i * 20 + 10;
				done = true;
			}

		}
	}
}
void createI(int i) {
	srand(time(NULL));
	bool done = false;
	while (done == false) {
		if (i == 9) {
			randomVal = ((rand() % 20 + 1) / 20.0) - 1;
			if (enemy1[0][1] != randomVal*30.0) {
				enemy1[i][0] = 0;
				enemy1[i][1] = randomVal*30.0;
				enemy1[i][2] = enemy1[0][2] - 20;
				done = true;
			}
		}
		else {
			randomVal = ((rand() % 20 + 1) / 20.0) - 1;
			if (enemy1[i + 1][1] != randomVal*30.0) {
				enemy1[i][0] = 0;
				enemy1[i][1] = randomVal*30.0;
				enemy1[i][2] = enemy1[i + 1][2] - 20;
				done = true;
			}
		}
		
	}
	}
void posnextBuf() {
	for (int i = 0; i < 10; i++)
	{
			enemy1[i][2] += 0.5f;
			if (enemy1[9][2] == 320) {
				memcpy(enemy1, enemybuffer1, sizeof(enemybuffer1));
				createBuffer();
				
			}
	}

}
void posnextConti() {
	for (int i = 0; i < 10; i++)
	{
		if (i == 9) {
//			printf("%d\n", enemy1[9][2]);
		}
		enemy1[i][2] += 2.0f;
			if (enemy1[i][2] == 216) {
				createI(i);
			}
		
	
	}

}

