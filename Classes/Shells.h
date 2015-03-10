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

	void setShellSpeed(int);//设置炮弹速度
	int getShellSpeed() const;//获取炮弹速度

private:
	int shellSpeed;//炮弹速度
};

#endif