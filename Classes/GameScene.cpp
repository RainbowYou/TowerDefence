#include"GameScene.h"
#include"Battery.h"
#include<fstream>
#include<iostream>
using namespace std;
using namespace cocos2d;


Scene* GameScene::createScene()
{
	Scene* scene = Scene::create();

	Layer* layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}


bool GameScene::init()
{
	//���ñ�����ɫΪ��ɫ
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
		return false;


	addBackground();//��ӱ���

	addTower();//�����

	//addBattery();//�����̨
#if READ_ROUTE
	readData();
#endif

	//this->schedule(schedule_selector())
	//�������������
	monsterMgr = MonsterManager::create();
	monsterMgr->setMonsterPosList(routeArray);
	this->addChild(monsterMgr);

	return true;
}

#if READ_ROUTE
void GameScene::readData()
{
	fstream routeFile("route.txt", ios::in);

	if (!routeFile)
	{
		cerr << "File could not be opened!" << endl;
		exit(1);
	}

	Point routePoint;
	while (routeFile >> routePoint.x >> routePoint.y)
	{
		routeArray.push_back(routePoint);
	}

}
#endif



void GameScene::addBattery()
{
	Point pos = tower->getPosition();

	//������̨����
	Sprite* sprite = Sprite::create("battery.png");
	battery = Battery::create();
	battery->bindWeaponSprite(sprite);
	battery->setPosition(Point(pos.x - 120, pos.y + 10));
	battery->setScale(0.3, 0.3);
	this->addChild(battery, 1);

	nextProjectile = NULL;
}


void GameScene::addBackground()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//����ͼƬ
	Sprite* bgSprite = Sprite::create("background1.png");
	bgSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(bgSprite, 0);
}


void GameScene::addTower()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	tower = Sprite::create("Tower.png");
	tower->setPosition(visibleSize.width - 50 , visibleSize.height / 2 + 130);
	tower->setScale(1.4, 1.6);

	this->addChild(tower);
}


void GameScene::onEnter()
{
	LayerColor::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		return true;
	};

	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameScene::onTouchEnded(Touch* touch, Event* event)
{
#if 0
	if (NULL != nextProjectile) return;

	// Choose touch to work with
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto touchPoint = touch->getLocation();

	nextProjectile = Sprite::create("shell.png");
	Point batteryPos = battery->getPosition();
	nextProjectile->setPosition(Point(batteryPos.x , batteryPos.y + 23));

	this->addChild(nextProjectile);
	// Add to projectiles vector
	projectiles.pushBack(nextProjectile);


	// Determine offset of location to projectile
	int offX = touchPoint.x - nextProjectile->getPosition().x;
	int offY = touchPoint.y - nextProjectile->getPosition().y;

	// Bail out if we are shooting down or backwards
	if (offX <= 0) return;

	// set tag
	nextProjectile->setTag(2);

	// Determine where we wish to shoot the projectile to
	int realX = visibleSize.width + (nextProjectile->getContentSize().width / 2);
	float ratio = (float)offY / (float)offX;
	int realY = (realX * ratio) + nextProjectile->getPosition().y;
	auto realDest = Point(realX, realY);

	// Determine the length of how far we're shooting
	int offRealX = realX - nextProjectile->getPosition().x;
	int offRealY = realY - nextProjectile->getPosition().y;
	float length = sqrtf((offRealX*offRealX) + (offRealY*offRealY));
	float velocity = 960 / 1; // 960pixels/1sec
	//float realMoveDuration = length / velocity;

	// Determine angle to face
	float angleRadians = atanf((float)offRealY / (float)offRealX);
	float angleDegrees = CC_RADIANS_TO_DEGREES(angleRadians);
	float cocosAngle = -1 * angleDegrees;
	float rotateSpeed = 0.5 / M_PI; // Would take 0.5 seconds to rotate 0.5 radians, or half a circle
	float rotateDuration = fabs(angleRadians * rotateSpeed);

	//��ת��̨
	battery->runAction(Sequence::create(
		RotateTo::create(rotateDuration, cocosAngle),
		CallFuncN::create(CC_CALLBACK_0(GameScene::finishShoot, this)),
		NULL));


	float duration, coeffcient;

	if (touchPoint.x >= nextProjectile->getPositionX()) coeffcient = 1.0f;
	else coeffcient = -1.0f;

	ccBezierConfig bezierConfig = battery->setBezierTrack(touchPoint,nextProjectile);

	battery->setShellSpeed(300.0f);//�����ڵ��ٶ�
	duration = 2 * coeffcient * (touchPoint.x - nextProjectile->getPositionX()) / battery->getShellSpeed();//�ڵ�����ʱ��

	BezierTo* bezierTo = BezierTo::create(duration, bezierConfig);

	//�ڵ�����
	nextProjectile->runAction(
		Sequence::create(
		bezierTo,
		CallFuncN::create(CC_CALLBACK_1(GameScene::spriteMoveFinished, this)),
		NULL));

	nextProjectile = NULL;
#endif

#if WRITE_ROUTE
	fstream routeFstream("route.txt", ios::app);

	if (!routeFstream)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	Point point;
	point.x = touch->getLocation().x;
	point.y = touch->getLocation().y;

	routeFstream << point.x << ' '<< point.y << endl;

	routeFstream.close();
#endif
}



void GameScene::finishShoot()
{
	// Ok to add now - we've finished rotation!
	this->addChild(nextProjectile);
	// Add to projectiles vector
	projectiles.pushBack(nextProjectile);

	nextProjectile = NULL;
}

void GameScene::spriteMoveFinished(Object* pSender)
{
	Sprite *sprite = (Sprite *)pSender;

	if (sprite->getTag() == 1)
	{ // target
		targets.eraseObject(sprite);
	}

	else if (sprite->getTag() == 2)
	{ // projectile
		projectiles.eraseObject(sprite);
	}

	this->removeChild(sprite);
}


void GameScene::menuCloseCallback(Object* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}