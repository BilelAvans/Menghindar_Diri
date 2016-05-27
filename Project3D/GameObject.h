#pragma once
#include "ModelObject.h"
#ifndef CollisionBox_H
#include "Objects/Collision/CollisionBox.h"
#endif // !COLLISIONBOX_H



class GameObject
{
private:
	float width;
	float length;
	float height;
	ModelObject* model;
protected:
	CollisionBox* collisionBox;
	float x;
	float y;
	float z;
public:
	GameObject(float x, float y, float z, float width, float length, float height, ModelObject* model);
	CollisionBox* getCollisionBox() {
		return collisionBox;
	}
	GameObject() {
		x = 0;
		y = 0;
		z = 0;
		width = 0;
		height = 0;
		length = 0;
		model = 0;
	}
	ModelObject* getModelObject() {
		return model;
	}
	virtual ~GameObject() = 0;
};




