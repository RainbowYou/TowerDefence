#ifndef WEAPON_H
#define WEAPON_H

#include<cocos2d.h>
using namespace cocos2d;

class Weapon:public Node
{
public:
	void bindWeaponSprite(Sprite*);//设置并绑定武器的精灵对象
protected:
	Sprite* weaponSprite;
};

#endif