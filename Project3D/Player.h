#pragma once
#ifndef GameObject_H


#ifdef __APPLE__
#include <glut/glut.h>
#else
#endif

#include "GameObject.h"
#endif // !GameObject_H
#include <GL/gl.h>


class Player : public GameObject {

	public:
		Player(float x, float y, float z, float width, float length, float height, ModelObject* model) : GameObject(x, y, z, width, length, height, model)
		{
			collisionBox = new CollisionBox(x, y, z, width, length, height);
		}

		void Draw(){
			glPushMatrix();
			glTranslatef(x, y, z);
			glScalef(.3, .3, .3);
			model->Draw();
			glPopMatrix();
		}

		void move(float x, float y, float z){
			this->x += x;
			this->y += y;
			this->z += z;
		}
};
