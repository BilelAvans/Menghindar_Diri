//
// Created by Gilian Joosen on 18/05/16.
//
#pragma once
class CollisionBox {
public:
	CollisionBox(float x, float y, float z, float width, float length, float height);
	bool intersect(CollisionBox *collisionBox);
	void move(float x, float y , float z);
	float getx() {
		return x;
	}
	float gety() {
		return y;
	}
	float getz() {
		return z;
	}
protected:
private:
	float x, y, z, width, length, height;

};