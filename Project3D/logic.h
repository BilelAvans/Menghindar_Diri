
#include <math.h>
#include <cmath>
#include <string>
#include "enemy.h"
#include "Player.h"
#ifndef _LOGIC
#define _LOGIC
double enemy1[10][3];
enemy enemybuffer1[10];
void create(double width);
void collisioncheck(Player *player);
void posnextConti();
#endif