#include"Monster.h"

Monster::Monster()
{
	moveController = NULL;
	mISpeed = MONSTER_SPEED_INIT;
}


Monster::~Monster()
{

}


bool Monster::init()
{
	moveController = ControllerSimpleMove::create(this);
	this->addChild(moveController);
	return true;
}


void Monster::moveByPosList(std::vector<Point> posList)
{
	if (posList.size() < 1)
	{
		return;
	}

	moveController->moveByPosList(posList, 2, getiSpeed());
}