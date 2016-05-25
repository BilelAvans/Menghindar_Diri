#pragma once

class CollisionBox {
public:
	CollisionBox(float x, float y, float z, float width, float length, float height);
	bool intersect(CollisionBox *collisionBox);
protected:
private:
	float x, y, z, width, length, height;

};

CollisionBox::CollisionBox(float x, float y, float z, float width, float length, float height) {

}

bool intersect(CollisionBox *collisionBox) {
	return true;
}