#include "Player.h"

void Player::Draw() {
	if (isLit % 10 > 5)
	{
		return;
	}
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(.3, .3, .3);
	glRotatef(180, 0, 1, 0);
	model->draw();
	glPopMatrix();
}

void Player::move(float x, float y, float z) {
	this->x += x;
	this->y += y;
	this->z += z;
	this->collisionBox->move(x, y, z);
}