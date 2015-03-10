#ifndef SHELLMANAGER_H
#define SHELLMANAGER_H

#include<cocos2d.h>
#include"Shells.h"
using namespace cocos2d;

class ShellManager :public Node
{
public:
	static ShellManager* create();
	bool init();

	Shells* getShell();//获取子弹
private:
	void createShells();//创建子弹

	Vector<Shells*> shellList;//子弹列表
};

#endif