#ifndef CONTROLLERMOVEBASE_H
#define CONTROLLERMOVEBASE_H

#include"ControllerBase.h"
#include"Entity.h"

//检查移动的间隔时间，时间越短，移动越快，也越平滑
#define CHECK_MOVE_SPEED_LVL1 0.1f
#define CHECK_MOVE_SPEED_LVL2 0.04f
#define CHECK_MOVE_SPEED_LVL3 0.03f

#define SPEED 1

class ControllerMoveBase :public ControllerBase
{
public:
	ControllerMoveBase();
	~ControllerMoveBase();

	CC_SYNTHESIZE(int, mISpeed, iSpeed);

protected:
	Entity* mEntity;//实体对象
	bool isMoving;//是否移动
	bool isXLeft;//x方向上是否左移
	bool isYUp;//y方向上时候向上移动
	int checkMoveSpeed;//检查移动的间隔时间，时间越短，移动越快

	//给定当前坐标和目的坐标，计算出下一次要设置的目标
	Point getNextPos(Point curPos, Point destPos);
};

#endif