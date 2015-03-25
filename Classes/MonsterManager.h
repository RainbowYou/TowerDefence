#ifndef MONSTERMANAGER_H
#define MONSTERMANAGER_H

#include"Monster.h"
#include"cocos2d.h"
using namespace cocos2d;

class MonsterManager :public Node
{
public:
	MonsterManager();
	~MonsterManager();

	static MonsterManager* create();
	virtual bool init();

	void setMonsterPosList(std::vector<Point>);

	void createMonsters();
	int getNotShowMonsterCount() const;//获取还没出场的怪物数量
	Point getMonsterStartPos() const;//获取怪物出场坐标
	Point getMonsterEndPos() const;//获取怪物终点坐标
	Vector<Monster*> getMonsterList() const;//获取怪物列表

private:
	Vector<Monster*> monsterList;//怪物列表
	Vector<Monster*> notShowMonsterList;//未出场怪物列表
	std::vector<Point> monsterPosList;//存放所有怪物的坐标对象
	float showTimeCount;//用于计算怪物出场时间
	void showMonster(float dt);//检查是否有新怪物出场

};

#endif