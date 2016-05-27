//
// Created by Gilian Joosen on 18/05/16.
//

#include "CollisionBox.h"

CollisionBox::CollisionBox(float x, float y,float z, float width,float length, float height){
	this->x = x;
	this->y = y;
	this->z = z;
	this->width = width;
	this->length = length;
	this->height = height;
}
void CollisionBox::move(){
	z += 2.0f;
}
bool CollisionBox::intersect(CollisionBox *collisionBox){
	float xMin = x-width/2;
	float xMax = xMin + width;

	float yMin = y-length/2;
	float yMax = yMin + length;

	float zMin = z-height/2;
	float zMax = zMin + height;

	float xMin2 = collisionBox->x-collisionBox->width/2;
	float xMax2 = xMin2 + collisionBox->width;

	float yMin2 = collisionBox->y - collisionBox->length/2;
	float yMax2 = yMin2 + collisionBox->length;

	float zMin2 = collisionBox->z - collisionBox->height/2;
	float zMax2 = zMin2 + collisionBox->height;
	
	return (xMin <= xMax2 && xMax >= xMin2) &&
		   (yMin <= yMax2 && yMax >= yMin2) &&
		   (zMin <= zMax2 && zMax >= zMin2);
	
}
