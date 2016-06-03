#pragma once
#include "ModelObject.h"
#ifndef CollisionBox_H
#include "Objects/Collision/CollisionBox.h"
#include "Objects/node/Node.h"

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
		Node* model;
public:
	GameObject(float x, float y, float z, float width, float length, float height, Node* model);
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
		Node* getModelObject() {
		return model;
	}
	virtual ~GameObject() = 0;
		virtual void Draw() = 0;
		virtual void move(float x, float y, float z) = 0;
};




