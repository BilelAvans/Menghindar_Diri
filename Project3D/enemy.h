#pragma once
#ifndef GameObject_H
#include "GameObject.h"
#endif // !GameObject_H


class enemy : public GameObject {

public:
	enemy(float x, float y, float z, float width, float length, float height, ModelObject* model) : GameObject(x, y, z, width, length, height, model)
	{
		collisionBox = new CollisionBox(x, y, z, width, length, height);
	}
	enemy::~enemy() {}
	enemy()
	{

	}
	void move() {
		z += 0.5f;
		
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