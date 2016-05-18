//
// Created by Gilian Joosen on 18/05/16.
//

#ifndef MENGHINDAR_DIRI_COLLISIONBOX_H
#define MENGHINDAR_DIRI_COLLISIONBOX_H


class CollisionBox {
	public:
		CollisionBox(float x, float y, float z, float width, float length, float height);
		bool intersect(CollisionBox *collisionBox);
	protected:
	private:
		float x, y, z, width, length, height;

};


#endif //MENGHINDAR_DIRI_COLLISIONBOX_H
