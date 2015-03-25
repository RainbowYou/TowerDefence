#include"ControllerSimpleMove.h"
#include<algorithm>
using namespace std;

ControllerSimpleMove::ControllerSimpleMove()
{
	moveTimeCount = 0;
	moveSpan = 0;
}


ControllerSimpleMove::~ControllerSimpleMove()
{

}


ControllerSimpleMove* ControllerSimpleMove::create(Entity* entity)
{
	ControllerSimpleMove* ctrlSimpleMove = new ControllerSimpleMove();

	if (ctrlSimpleMove&&ctrlSimpleMove->init(entity))
	{
		ctrlSimpleMove->autorelease();
	}

	else
	{
		CC_SAFE_DELETE(ctrlSimpleMove);
	}
	return ctrlSimpleMove;
}

bool ControllerSimpleMove::init(Entity* entity)
{
	this->mEntity = entity;

	//����Ϸ��ÿһ֡����checkMoveUpdate����
	this->schedule(schedule_selector(ControllerSimpleMove::checkMoveUpdate));

	return true;
}


void ControllerSimpleMove::checkMoveUpdate(float dt)
{
	if (isMoving)
	{
		moveTimeCount += dt * 1000;

		if (moveTimeCount >= moveSpan)
		{
			moveTimeCount = 0;
			moveOneStep();
		}
	}
}


void ControllerSimpleMove::moveOneStep()
{
	Sprite* sprite = mEntity->getSprite();

	if (sprite != NULL)
	{
		Point entityPos = mEntity->getPosition();
		Point curDestPos = curDestPos;

		//ȡ����һ���ƶ������
		entityPos = getNextPos(entityPos, curDestPos);

		//�ƶ�ʵ��
		mEntity->setPosition(entityPos);

		//���ﵱǰĿ�ĵأ���ʼ��һ��Ŀ�ĵ�
		if (entityPos.x == curDestPos.x&&entityPos.y == curDestPos.y)
		{
			if (movePosList.size() > 0)
			{
				nextMovePos();
			}
		}
	}
}


void ControllerSimpleMove::nextMovePos()
{
	if (movePosList.size() < 1)
	{
		return;
	}

	curDestPos = movePosList.at(0);

	movePosList.erase(movePosList.begin());
}


void ControllerSimpleMove::moveByPosList(std::vector<Point> posList)
{
	if (posList.size() < 1)
	{
		return;
	}

	this->movePosList.clear();
	this->movePosList.push_back(posList.at(0));

	nextMovePos();

	this->isMoving = true;
}


void ControllerSimpleMove::moveByPosList(std::vector<Point> posList, int iSpeed)
{
	this->mISpeed = iSpeed;
	moveByPosList(posList);
}


void ControllerSimpleMove::moveByPosList(std::vector<Point> posList, int iSpeed, int iSpanTime)
{
	moveSpan = iSpanTime;
	moveByPosList(posList, iSpeed);
}

void ControllerSimpleMove::moveByPos(Point pos)
{
	if (isMoving == false )
	{
		std::vector<Point> posList;
		posList.push_back(pos);
		moveByPosList(posList);
	}
}