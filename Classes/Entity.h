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

	void hurtMe(int iHurtValue);//������
	bool isDead();//�Ƿ�����
protected:
	virtual void onDead();//ʵ������ʱ��
	virtual void onBindSprite();//�󶨾�������ǵ���
	virtual void onHurt(int);//���˺�ʱ����

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

