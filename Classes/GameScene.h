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

//如果向保存怪物路线的文件输入数据，则将WRITE_ROUTE值赋为1，否则为0
#define WRITE_ROUTE 0

//如果向保存怪物路线的文件读取数据，则取值为1，否则为0
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

	void onTouchEnded(Touch* touch, Event* event);//鼠标监听事件，鼠标左键按下结束

	void update(float dt);

private:
	void addBackground();
	void addTower();
	void addBattery();

	//添加物理世界
	void addPhysicWorld();
	//添加地面
	void addGround();

#if READ_ROUTE
	void readData();
#endif

	void shoot(int);//炮塔射击敌人，当前仅仅用于测试效果

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

	b2World* gameWorld;//游戏世界
	b2Body* groundBody;//地面

};

#endif