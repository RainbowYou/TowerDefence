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
	int getNotShowMonsterCount() const;//��ȡ��û�����Ĺ�������
	Point getMonsterStartPos() const;//��ȡ�����������
	Point getMonsterEndPos() const;//��ȡ�����յ�����
	Vector<Monster*> getMonsterList() const;//��ȡ�����б�

private:
	Vector<Monster*> monsterList;//�����б�
	Vector<Monster*> notShowMonsterList;//δ���������б�
	std::vector<Point> monsterPosList;//������й�����������
	float showTimeCount;//���ڼ���������ʱ��
	void showMonster(float dt);//����Ƿ����¹������

};

#endif