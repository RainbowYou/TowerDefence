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

	void setBatteryPosition(int,int);//设置炮台位置
	Point getBatteryPosition() const;//获取炮台位置

public:
	ccBezierConfig setBezierTrack(Point, Sprite*);//设置炮弹轨迹（贝塞尔曲线）
};

#endif