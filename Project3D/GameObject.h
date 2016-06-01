#pragma once
#include "ModelObject.h"
#ifndef CollisionBox_H
#include "Objects/Collision/CollisionBox.h"
#endif // !COLLISIONBOX_H



class GameObject
{
private:

protected:
	CollisionBox* collisionBox;
		float x;
		float y;
		float z;
		float width;
		float length;
		float height;
		ModelObject* model;
public:
	GameObject(float x, float y, float z, float width, float length, float height, ModelObject* model);
	CollisionBox* getCollisionBox() {
		return collisionBox;
	}
	ModelObject* getModelObject() {
		return model;
	}
	virtual ~GameObject() = 0;
		virtual void Draw() = 0;
		virtual void move(float x, float y, float z) = 0;
};




