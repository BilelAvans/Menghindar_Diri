#include "GameObject.h"
#include "Objects/Collision/CollisionBox.h"


GameObject::GameObject(float x, float y, float z,float width, float length, float height, Node* model)
{
	this->x=x;
	this->y=y;
	this->z = z;
	this->width = width;
	this->length = length;
	this->height = height;
	this->model = model;
}
GameObject::~GameObject() {}


