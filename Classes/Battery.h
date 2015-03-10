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

	void setBatteryPosition(int,int);//������̨λ��
	Point getBatteryPosition() const;//��ȡ��̨λ��

public:
	ccBezierConfig setBezierTrack(Point, Sprite*);//�����ڵ��켣�����������ߣ�
};

#endif