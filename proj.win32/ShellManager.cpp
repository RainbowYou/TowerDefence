#include"ShellManager.h"

#define MAX_SHELL_NUM 10

ShellManager* ShellManager::create()
{
	ShellManager* shellManager = new ShellManager();
	if (shellManager&&shellManager->init())
		shellManager->autorelease();

	else
		CC_SAFE_DELETE(shellManager);
	return shellManager;
}

bool ShellManager::init()
{
	createShells();
	return true;
}

void ShellManager::createShells()
{
	Shells* shell = NULL;

	for (int i = 1; i <= MAX_SHELL_NUM; i++)
	{
		shell = Shells::create();

		shellList.pushBack(shell);
		this->addChild(shell);
	}

}

Shells* ShellManager::getShell()
{
	for (auto shell : shellList)
	{
		return shell;
	}
}