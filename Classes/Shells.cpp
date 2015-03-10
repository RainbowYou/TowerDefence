#include"Shells.h"

bool Shells::init()
{
	Sprite* sprite = Sprite::create("shell.png");

	//�󶨾������
	this->bindWeaponSprite(sprite);

	return true;
}

void Shells::setShellSpeed(int speed)
{
	shellSpeed = speed;
}

int Shells::getShellSpeed() const
{
	return shellSpeed;
}
