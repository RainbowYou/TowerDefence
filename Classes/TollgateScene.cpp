#include"TollgateScene.h"
#include"Battery.h"
using namespace cocos2d;


Scene* TollgateScene::createScene()
{
	Scene* scene = Scene::create();

	Layer* layer = TollgateScene::create();

	scene->addChild(layer);

	return scene;
}


bool TollgateScene::init()
{
	//设置背景颜色为白色
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
		return false;

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//创建炮台精灵
	Sprite* sprite = Sprite::create("battery.png");
	battery = Battery::create();
	battery->bindWeaponSprite(sprite);
	battery->setPosition(Point(battery->getContentSize().width / 2 + 25, visibleSize.height / 2));
	this->addChild(battery,1);

	nextProjectile = NULL;

	//背景图片
	Sprite* bgSprite = Sprite::create("Qintomb_map_bg_r.png");
	bgSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	bgSprite->setScale(3, 3);//改变背景图层大小
	this->addChild(bgSprite, 0);

	return true;
}

void TollgateScene::onEnter()
{
	LayerColor::onEnter();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		return true;
	};

	listener->onTouchEnded = CC_CALLBACK_2(TollgateScene::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void TollgateScene::onTouchEnded(Touch* touch, Event* event)
{
	if (NULL != nextProjectile) return;

	// Choose touch to work with
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto touchPoint = touch->getLocation();

	// Set up initial location of projectile
	nextProjectile = Sprite::create("shell.png");
	nextProjectile->setPosition(Point(50, visibleSize.height / 2));

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

	//旋转炮台
	battery->runAction(Sequence::create(
		RotateTo::create(rotateDuration, cocosAngle),
		CallFuncN::create(CC_CALLBACK_0(TollgateScene::finishShoot, this)),
		NULL));


	ccBezierConfig bezierConfig = battery->setBezierTrack(touchPoint,nextProjectile);
	//BezierTo* bezierTo = BezierTo::create(realMoveDuration, bezierConfig);

	float duration;
	battery->setShellSpeed(300.0f);//设置炮弹速度
	duration = 2 * (touchPoint.x - nextProjectile->getPositionX()) / battery->getShellSpeed();//炮弹飞行时间

	BezierTo* bezierTo = BezierTo::create(duration, bezierConfig);

	//炮弹发射
	nextProjectile->runAction(
		Sequence::create(
		bezierTo,
		CallFuncN::create(CC_CALLBACK_1(TollgateScene::spriteMoveFinished, this)),
		NULL));
}



void TollgateScene::finishShoot()
{
	// Ok to add now - we've finished rotation!
	this->addChild(nextProjectile);
	// Add to projectiles vector
	projectiles.pushBack(nextProjectile);

	nextProjectile = NULL;
}

void TollgateScene::spriteMoveFinished(Object* pSender)
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


void TollgateScene::menuCloseCallback(Object* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}