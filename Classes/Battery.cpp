#include"Battery.h"


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

        endPoint.x = 2 * touchPoint.x - startPoint.x;	
		endPoint.y = startPoint.y;

		//控制点即为鼠标触点
		bezierConfig.controlPoint_1 = touchPoint;
		bezierConfig.controlPoint_2 = touchPoint;

		bezierConfig.endPosition = endPoint;
		
		return bezierConfig;
    }
}

	

