#include"ControllerMoveBase.h"

ControllerMoveBase::ControllerMoveBase()
{
	isMoving = false;
	isXLeft = false;
	isYUp = false;
	mISpeed = SPEED;
	checkMoveSpeed = CHECK_MOVE_SPEED_LVL2;
	mEntity = NULL;
}

ControllerMoveBase::~ControllerMoveBase()
{

}


Point ControllerMoveBase::getNextPos(Point curPos,Point destPos)
{
	//判断移动方向
	if (curPos.x > destPos.x) isXLeft = true;
	else isXLeft = false;

	if (curPos.y < destPos.y) isYUp = true;
	else isYUp = false;


	//根据移动方向和速度值改变当前方向
	if (curPos.x < destPos.x&&isXLeft == false)
	{
		curPos.x += mISpeed;
		if (curPos.x > destPos.x)
		{
			curPos.x = destPos.x;
		}
    }

	else if (curPos.x > destPos.x&&isXLeft == true)
	{
		curPos.x -= mISpeed;
		if (curPos.x < destPos.x)
		{
			curPos.x = destPos.x;
		}
	}	

	if (curPos.y < destPos.y&&isYUp == true)
	{
		curPos.y += mISpeed;
		if (curPos.y > destPos.y)
		{
			curPos.y = destPos.y;
		}
	}

	else if (curPos.y > destPos.y&&isYUp == false)
	{
		curPos.y -= mISpeed;
		if (curPos.y < destPos.y)
		{
			curPos.y = destPos.y;
		}
	}

	return curPos;
}