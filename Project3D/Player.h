#pragma once
#ifndef GameObject_H


#ifdef __APPLE__
#include <glut/glut.h>
#else
#include <GL\freeglut.h>
#endif

#include "GameObject.h"
#endif 


class Player : public GameObject {

	public:
		Player(float x, float y, float z, float width, float length, float height, Node* model) : GameObject(x, y, z, width, length, height, model)
		{
			collisionBox = new CollisionBox(x-0.5f, y-0.5f, z-0.5f, width, length, height);
			life = 3;
		}

		void Draw(void);

		void move(float, float, float);

	int isLit = 0;
	int score = 0;
	int life = 3;
	int invince = 0;
};
