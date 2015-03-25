#include"Entity.h"

Entity::Entity()
{
	mSprite = NULL;
	mSName = "";
	mIHP = 1;
	mIDefense = 1;
	mIsDead = false;
	mISpeed = 1;
	mILevel = 1;
}

Entity::~Entity()
{

}

void Entity::bindSprite(Sprite* sprite)
{
	if (this->mSprite != NULL)
	{
		mSprite->removeFromParentAndCleanup(true);
	}

	this->mSprite = sprite;
	this->addChild(mSprite);

	Size size = mSprite->getContentSize();
	this->setContentSize(size);

	onBindSprite();
}


Sprite* Entity::getSprite() const
{
	return this->mSprite;
}


void Entity::hurtMe(int iHurtValue)
{
	if (mIsDead)
		return;
	//最小值为1
	if (iHurtValue <= getiDefense())
	{
		iHurtValue = 1;
	}

	int iCurHP = getiHP();
	int iAfterHP = iCurHP - iHurtValue;

	onHurt(iHurtValue);

	if (iAfterHP > 0)
	{
		setiHP(iAfterHP);
	}

	else
	{
		mIsDead = true;
		//死亡
		onDead();
	}
}

bool Entity::isDead()
{
	return this->mIsDead;
}


void Entity::onDead()
{

}


void Entity::onBindSprite()
{

}


void Entity::onHurt(int iHurtValue)
{

}