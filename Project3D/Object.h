#pragma once
#include "ModelObject.h"
class Object
{
public:
	Object(float x, float y, float z,float width, float length, float height, ModelObject model);
	virtual ~Object()=0;
};

Object::~Object() {}

