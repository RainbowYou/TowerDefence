//让怪物按指定坐标列表移动

#ifndef CONTROLLERSIMPLEMOVE_H
#define CONTROLLERSIMPLEMOVE_H

#include"ControllerMoveBase.h"
#include"Entity.h"

class ControllerSimpleMove :public ControllerMoveBase
{
public:
	ControllerSimpleMove();
	~ControllerSimpleMove();

	static ControllerSimpleMove* create(Entity* entity);
	bool init(Entity* entity);

	void checkMoveUpdate(float dt);

	//按照给定的坐标移动
	void moveByPosList(std::vector<Point>);

	//按照给定的坐标点和移动速度移动
	void moveByPosList(std::vector<Point>, int);

	//按照给定的坐标点、速度、移动时间间隔移动
	void moveByPosList(std::vector<Point>, int, int);

	//按照给定坐标移动
	void moveByPos(Point);

private:
	void moveOneStep();//移动一步
	void nextMovePos();//设置下一个移动目的点

private:
	std::vector<Point> movePosList;//移动目的列表
	Point curDestPos;//当前移动目的地
	float moveSpan;//移动时间间隔
	float moveTimeCount;//计时器

};

#endif