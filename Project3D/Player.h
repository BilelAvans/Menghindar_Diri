#pragma once
#ifndef GameObject_H
#include "GameObject.h"
#endif // !GameObject_H


class Player : public GameObject {

	public:
		Player(float x, float y, float z, float width, float length, float height, ModelObject* model) : GameObject(x, y, z, width, length, height, model)
		{
			collisionBox = new CollisionBox(x, y, z, width, length, height);
		}

};
