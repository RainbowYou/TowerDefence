#ifndef SHELLS_H
#define SHELLS_H

#include<cocos2d.h>
#include"Weapon.h"
using namespace cocos2d;

class Shells :public Weapon
{
public:
	CREATE_FUNC(Shells);
	virtual bool init();

	void setShellSpeed(int);//�����ڵ��ٶ�
	int getShellSpeed() const;//��ȡ�ڵ��ٶ�

private:
	int shellSpeed;//�ڵ��ٶ�
};

#endif