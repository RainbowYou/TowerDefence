#include"Battery.h"


void Battery::setBatteryPosition(int x, int y)
{
	this->setPosition(x, y);
}

Point Battery::getBatteryPosition() const
{
	return this->getPosition();
}

/*void Battery::setBatteryDirection(int direction)
{
	batteryDirection = direction;
}

int Battery::getBatteryDirection() const
{
	return batteryDirection;
}

/*void Battery::setDeltaAngle(float angle)
{
	batteryAngle = angle;
}

float Battery::getDeltaAngle() const
{
	return batteryAngle;
}


void Battery::runBattery()
{
	int frameNumber = 11;//炮台动画帧数
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*> frameVec;

	for (int i = 0; i <= frameNumber; i++)
	{
		frame = SpriteFrame::create(StringUtils::format("%d.png",i),Rect(63,20,75,120));
		frameVec.pushBack(frame);
	}

	Animation* animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);//无限循环动作
	animation->setDelayPerUnit(0.1f);//设置每帧之间延迟时间

	Animate* action = Animate::create(animation);

	weaponSprite->runAction(action);
}*/

bool Battery::init()
{
	return true;
}



ccBezierConfig Battery::setBezierTrack(Point touchPoint, Sprite* nextProjectile)
{
	ccBezierConfig bezierConfig;

	Point controlPoint, middlePoint;

	Point startPoint = nextProjectile->getPosition();
	Point endPoint = touchPoint;

	float slope = (endPoint.y - startPoint.y) / (endPoint.x - endPoint.y);

	middlePoint.x = (startPoint.x + endPoint.x) / 2;
	middlePoint.y = (startPoint.y + endPoint.y) / 2;

	controlPoint.x = 2;
	controlPoint.y = (controlPoint.x - middlePoint.x) * slope + middlePoint.y;

	bezierConfig.controlPoint_1 = controlPoint;
	bezierConfig.controlPoint_2 = controlPoint;
	bezierConfig.endPosition = endPoint;

	return bezierConfig;
}

