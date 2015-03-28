#include"MonsterManager.h"

MonsterManager::MonsterManager()
{
	showTimeCount = 0;
}

MonsterManager::~MonsterManager()
{

}


MonsterManager* MonsterManager::create()
{
	MonsterManager* monsterMgr = new MonsterManager();

	if (monsterMgr&&monsterMgr->init())
	{
		{
			monsterMgr->autorelease();
		}
	}

	else
	{
		CC_SAFE_DELETE(monsterMgr);
	}

	return monsterMgr;
}


bool MonsterManager::init()
{
	createMonsters();
	return true;
}


void MonsterManager::setMonsterPosList(std::vector<Point> pos)
{
	this->monsterPosList = pos;
}


int MonsterManager::getNotShowMonsterCount() const
{
	return notShowMonsterList.size();
}


Vector<Monster*> MonsterManager::getMonsterList() const
{
	return monsterList;
}


Point MonsterManager::getMonsterStartPos() const
{
	return monsterPosList.at(0);
}

Point MonsterManager::getMonsterEndPos() const
{
	return monsterPosList.at(monsterPosList.size() - 1);
}


void MonsterManager::createMonsters()
{
	auto monster = Monster::create();
	monster->setVisible(false);

	Sprite* sprite = Sprite::create("Monster/monster_4.png");
	monster->bindSprite(sprite);

	monsterList.pushBack(monster);

	notShowMonsterList.pushBack(monster);

	this->addChild(monster);

	this->schedule(schedule_selector(MonsterManager::showMonster));
}


void MonsterManager::showMonster(float dt)
{
	int iNotShowMonsterCount = notShowMonsterList.size();

	if (iNotShowMonsterCount > 0)
	{
		showTimeCount += dt;
	}

	auto monsterFirstPos = getMonsterStartPos();
	//auto monsterFirstPos = getMonsterEndPos();
	Vector<Monster*> monsterWantToDelete;
	for (auto monster : notShowMonsterList)
	{
		if (showTimeCount >= monster->getfShowTime())
		{
			monsterWantToDelete.pushBack(monster);

			monster->setPosition(monsterFirstPos);
			monster->setVisible(true);
			
			monster->moveByPosList(monsterPosList);

			//monsterPosList.erase(monsterPosList.begin());//删除引用完的坐标值
		}
	}

	for (auto monster : monsterWantToDelete)
	{
		notShowMonsterList.eraseObject(monster);
	}
	
	
}


