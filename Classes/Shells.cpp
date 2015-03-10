#include"Shells.h"

bool Shells::init()
{
	Sprite* sprite = Sprite::create("shell.png");

	//绑定精灵对象
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
