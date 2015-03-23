#ifndef BATTERY_H
#define BATTERY_H

#include"Battery.h"
#include"Weapon.h"
#include"Shells.h"
#include"ShellManager.h"


class Battery :public Weapon
{
public:
	CREATE_FUNC(Battery);
	virtual bool init();

public:
	ccBezierConfig setBezierTrack(Point, Sprite*);//�����ڵ��켣�����������ߣ�

	void setShellSpeed(float);//�����ڵ��ٶ�
	float getShellSpeed() const;//��ȡ�ڵ��ٶ�

private:
	float shellSpeed;//�ڵ��ٶ�
};

#endif