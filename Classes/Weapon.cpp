#include"Weapon.h"

void Weapon::bindWeaponSprite(Sprite* sprite)
{
	weaponSprite = sprite;
	this->addChild(weaponSprite);
}
