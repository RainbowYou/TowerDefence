#include"Battery.h"


void Battery::setBatteryPosition(int x, int y)
{
	this->setPosition(x, y);
}

Point Battery::getBatteryPosition() const
{
	return this->getPosition();
}


bool Battery::init()
{
	return true;
}


void Battery::setShellSpeed(float s)
{
	this->shellSpeed = s;
}


float Battery::getShellSpeed() const
{
	return this->shellSpeed;
}


ccBezierConfig Battery::setBezierTrack(Point touchPoint, Sprite* nextProjectile)
{
	if (touchPoint.y >= nextProjectile->getPositionY())
	{
		ccBezierConfig bezierConfig;

		Point startPoint = nextProjectile->getPosition();
		Point endPoint;

		if (touchPoint.x > startPoint.x)//如果鼠标触点位于炮台的右边
			endPoint.x = 2 * touchPoint.x - startPoint.x;
		else//鼠标触点在炮台左边
			endPoint.x = 2 * startPoint.x - touchPoint.x;

		endPoint.y = startPoint.y;

		//控制点即为鼠标触点
		bezierConfig.controlPoint_1 = touchPoint;
		bezierConfig.controlPoint_2 = touchPoint;

		bezierConfig.endPosition = endPoint;
		
		return bezierConfig;
}
	}

	

