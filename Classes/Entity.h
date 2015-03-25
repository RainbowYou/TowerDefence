#ifndef ENTITY_H
#define ENTITY_H

#include"cocos2d.h"
using namespace cocos2d;

class Entity :public Node
{
public:
	Entity();
	~Entity();

	void bindSprite(Sprite*);
	Sprite* getSprite() const;

	void hurtMe(int iHurtValue);//被攻击
	bool isDead();//是否死亡
protected:
	virtual void onDead();//实体死亡时用
	virtual void onBindSprite();//绑定精灵对象是调用
	virtual void onHurt(int);//受伤害时调用

private:
	Sprite* mSprite;

	CC_SYNTHESIZE(int, mID, ID);//entity ID
	CC_SYNTHESIZE(int, mIModelID, iModelID);//model ID
	CC_SYNTHESIZE(std::string, mSName, sName);//name
	CC_SYNTHESIZE(int, mIHP, iHP);//HP
	CC_SYNTHESIZE(int, mIDefense, iDefense);//defense
	CC_SYNTHESIZE(int, mISpeed, iSpeed);//move speed
	CC_SYNTHESIZE(int, mILevel, iLevel);//range

	bool mIsDead;//to mark whether dead
};


#endif

