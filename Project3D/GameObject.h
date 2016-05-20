#pragma once
#include "ModelObject.h"
#include "Objects/Collision/CollisionBox.h"
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



