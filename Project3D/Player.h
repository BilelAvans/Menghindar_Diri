#pragma once
#ifndef GameObject_H


#ifdef __APPLE__
#include <glut/glut.h>
#else
#include <GL\freeglut.h>
#endif

#include "GameObject.h"
#endif // !GameObject_H


class Player : public GameObject {

	public:
		Player(float x, float y, float z, float width, float length, float height, Node* model) : GameObject(x, y, z, width, length, height, model)
		{
			collisionBox = new CollisionBox(x-0.5, y-0.5, z-0.5, width, length, height);
		}

		void Draw(){
			glPushMatrix();
			glTranslatef(x, y, z);
			glScalef(0.3f, 0.3f, 0.3f);
			glRotatef(180, 0, 1, 0);
			model->draw();
			glPopMatrix();
		}

		void move(float x, float y, float z){
			this->x += x;
			this->y += y;
			this->z += z;
			this->collisionBox->move(x,y,z);
		}
};
