#pragma once
#ifndef GameObject_H
#ifdef __APPLE__
#include <glut/glut.h>
#else
#include <GL\freeglut.h>
#endif
#include "GameObject.h"
#endif // !GameObject_H


class enemy : public GameObject {

public:
	double random;
	enemy(float x, float y, float z, float width, float length, float height, Node* model, double random) : GameObject(x, y, z, width, length, height, model)
	{
		collisionBox = new CollisionBox(x-0.5f, y-0.5f, z-0.5f, width, length, height);
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