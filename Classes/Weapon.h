#ifndef WEAPON_H
#define WEAPON_H

#include<cocos2d.h>
using namespace cocos2d;

class Weapon:public Node
{
public:
	void bindWeaponSprite(Sprite*);//���ò��������ľ������
protected:
	Sprite* weaponSprite;
};

#endif