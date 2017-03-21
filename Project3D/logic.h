
#include <math.h>
#include <cmath>
#include <string>
#include "enemy.h"
#include "Player.h"
#ifndef _LOGIC
#define _LOGIC
extern double enemy1[10][3];
extern enemy enemybuffer1[10];
void create(double width);
bool collisioncheck(Player *player);
void posnextConti();
void init();
#endif