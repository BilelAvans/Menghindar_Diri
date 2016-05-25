#pragma once
#include "ModelObject.h"
#ifndef CollisionBox_H
#include "CollisionBox.h"
#endif // !COLLISIONBOX_H



class GameObject
{
private:
	float x;
	float y;
	float z;
	float width;
	float length;
	float height;
	ModelObject* model;
protected:
	CollisionBox* collisionBox;
public:
	GameObject(float x, float y, float z, float width, float length, float height, ModelObject* model);
	CollisionBox* getCollisionBox() {
		return collisionBox;
	}
	ModelObject* getModelObject() {
		return model;
	}
	virtual ~GameObject()=0;
};

GameObject::GameObject(float x, float y, float z, float width, float length, float height, ModelObject* model) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->width = width;
	this->length = length;
	this->height = height;
	this->model = model;
}



