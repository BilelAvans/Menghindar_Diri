#include "Player.h"
#include <iostream>

void Player::Draw() {
	if (isLit % 10 > 5 || invince % 10 > 5)
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
	if ((this->x < -22 && x < 0) || (this->x > 0 && x > 0))
	{
		return;
	}

	std::cout << this->x;
	this->x += x;
	this->y += y;
	this->z += z;
	this->collisionBox->move(x, y, z);
}