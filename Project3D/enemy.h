#pragma once
#ifndef GameObject_H
#include <math.h>
#include <cmath>
#include <string>
#include <time.h>
#include <cstdlib>
#include <iostream>
#ifdef __APPLE__
#include <glut/glut.h>
#else
#include <GL\freeglut.h>
#endif
#include "GameObject.h"
#endif // !GameObject_H

using namespace std;
class enemy : public GameObject {

public:
	double random;
	bool powers;
	int powerUp;
	enemy(float x, float y, float z, float width, float length, float height, Node* model, double random, bool power) : GameObject(x, y, z, width, length, height, model)
	{
		collisionBox = new CollisionBox(x-0.5f, y-0.5f, z-0.5f, width, length, height);
		powers = power;
		//cout << "power " << power << endl;
		if (powers == 1) {
			randomPower();
		}
	}
	~enemy() {}
	enemy()
	{

	}
	void move(float x, float y ,float z) {
		this->z+=z;
		
		collisionBox->move(x,y,z);
	}
	void Draw() {
		glPushMatrix();
		glTranslatef(x, y, z);
		glScalef(.3f, .3f, .3f);
		model->draw();
		glPopMatrix();
	}
	void randomPower() {
		srand(rand()*rand());
		int random = (((rand() % 100) * rand() * rand()*rand()))%3;
		if (random < 0) {
			powerUp = -random;
		}
		else {
			powerUp = random;
		}
		//cout << "powerup " << powerUp << endl;

	}
	float getx() {
		return x;//deze is voor breedte
	}
	float gety() {
		return y;
	}
	float getz() {
		return z;
	}
};