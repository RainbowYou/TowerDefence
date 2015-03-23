/*
It's used for loading game scene
*/

#ifndef TOLLGATESCENE_H
#define TOLLGATESCENE_H

#include<cocos2d.h>
#include"Battery.h"
using namespace cocos2d;

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

private:
	Vector<Sprite*> targets;
	Vector<Sprite*> projectiles;

	Battery* battery;
	Sprite* nextProjectile;
	Sprite* tower;
};

#endif