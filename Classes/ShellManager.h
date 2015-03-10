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

	Shells* getShell();//��ȡ�ӵ�
private:
	void createShells();//�����ӵ�

	Vector<Shells*> shellList;//�ӵ��б�
};

#endif