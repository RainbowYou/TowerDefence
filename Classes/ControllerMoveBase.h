#ifndef CONTROLLERMOVEBASE_H
#define CONTROLLERMOVEBASE_H

#include"ControllerBase.h"
#include"Entity.h"

//����ƶ��ļ��ʱ�䣬ʱ��Խ�̣��ƶ�Խ�죬ҲԽƽ��
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
	Entity* mEntity;//ʵ�����
	bool isMoving;//�Ƿ��ƶ�
	bool isXLeft;//x�������Ƿ�����
	bool isYUp;//y������ʱ�������ƶ�
	int checkMoveSpeed;//����ƶ��ļ��ʱ�䣬ʱ��Խ�̣��ƶ�Խ��

	//������ǰ�����Ŀ�����꣬�������һ��Ҫ���õ�Ŀ��
	Point getNextPos(Point curPos, Point destPos);
};

#endif