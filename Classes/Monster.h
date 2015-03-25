#ifndef MONSTER_H
#define MONSTER_H

#include"Entity.h"
#include"ControllerSimpleMove.h"

#define MONSTER_SPEED_INIT 1

class Monster :public Entity
{
public:
	Monster();
	~Monster();
	CREATE_FUNC(Monster);
	virtual bool init();

public:
	void moveByPosList(std::vector<Point> posList);

private:
	ControllerSimpleMove* moveController;
	CC_SYNTHESIZE(float, showTime, fShowTime);//³ö³¡¼ä¸ô£ºÃë
};

#endif