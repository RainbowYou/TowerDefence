//�ù��ﰴָ�������б��ƶ�

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

	//���ո����������ƶ�
	void moveByPosList(std::vector<Point>);

	//���ո������������ƶ��ٶ��ƶ�
	void moveByPosList(std::vector<Point>, int);

	//���ո���������㡢�ٶȡ��ƶ�ʱ�����ƶ�
	void moveByPosList(std::vector<Point>, int, int);

	//���ո��������ƶ�
	void moveByPos(Point);

private:
	void moveOneStep();//�ƶ�һ��
	void nextMovePos();//������һ���ƶ�Ŀ�ĵ�

private:
	std::vector<Point> movePosList;//�ƶ�Ŀ���б�
	Point curDestPos;//��ǰ�ƶ�Ŀ�ĵ�
	float moveSpan;//�ƶ�ʱ����
	float moveTimeCount;//��ʱ��

};

#endif