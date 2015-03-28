/*
It's used for loading game scene
*/

#ifndef TOLLGATESCENE_H
#define TOLLGATESCENE_H

#include<cocos2d.h>
#include<vector>
#include"Battery.h"
#include"editor-support\cocostudio\CCSGUIReader.h"
#include"ui\CocosGUI.h"
#include"MonsterManager.h"
#include"Box2D\Box2D.h"
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace cocos2d;

//����򱣴����·�ߵ��ļ��������ݣ���WRITE_ROUTEֵ��Ϊ1������Ϊ0
#define WRITE_ROUTE 0

//����򱣴����·�ߵ��ļ���ȡ���ݣ���ȡֵΪ1������Ϊ0
#define READ_ROUTE 1


#define SHOOT_NORMAL 1
#define SHOOT_PARTICLE 2

class GameScene :public LayerColor
{
public:
	CREATE_FUNC(GameScene);

	static Scene* createScene();

	virtual bool init();

public:
	int projectilesDestroyed;
	virtual void onEnter();

	void menuCloseCallback(Object* pSender);

	void finishShoot();
	void spriteMoveFinished(Object* pSender);

	void onTouchEnded(Touch* touch, Event* event);//�������¼������������½���

	void update(float dt);

private:
	void addBackground();
	void addTower();
	void addBattery();

	//�����������
	void addPhysicWorld();
	//��ӵ���
	void addGround();

#if READ_ROUTE
	void readData();
#endif

	void shoot(int);//����������ˣ���ǰ�������ڲ���Ч��

private:
	Vector<Sprite*> targets;
	Vector<Sprite*> projectiles;

	Battery* battery;
	Sprite* nextProjectile;
	Sprite* tower;

#if READ_ROUTE
	std::vector<Point> routeArray;
#endif

	MonsterManager* monsterMgr;

	b2World* gameWorld;//��Ϸ����
	b2Body* groundBody;//����

};

#endif