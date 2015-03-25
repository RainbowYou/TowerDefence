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
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace cocos2d;

//如果向保存怪物路线的文件输入数据，则将WRITE_ROUTE值赋为1，否则为0
#define WRITE_ROUTE 0

//如果向保存怪物路线的文件读取数据，则取值为1，否则为0
#define READ_ROUTE 1

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

private:
	void addBackground();
	void addTower();
	void addBattery();

#if READ_ROUTE
	void readData();
#endif

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

};

#endif