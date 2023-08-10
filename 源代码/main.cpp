//#pragma warning (disable: 4828)
#include"Player.h"
#include"Manager.h"
#include"Tool.h"
#include<functional>
using namespace std;

void gameClock(unsigned long& _gameTime)
{
	while (true)
	{
		_gameTime++;
		Sleep(1000);//时间尺度（按学期，小时和分钟记）
	}
}

void playStatus(Player& player)
{
	while (player.getHealth() > 0)
	{
		if (player.getHunger() < 30 || player.getEmotion() < 30)
		{
			unsigned long timeInitial = player.gameTime;
			Sleep(6000);
			int num = (player.gameTime - timeInitial) / 60;
			for (int i = 0; i < num; i++)
				player.setHealth(player.getHealth() - 5);
		}
	}
}
int main()
{
	//// 设置控制台模式以启用鼠标事件
	DWORD dwMode = 0;
	HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hConsoleInput, &dwMode);
	SetConsoleMode(hConsoleInput, dwMode | ENABLE_MOUSE_INPUT);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//字符输出utf-8
	system("chcp 65001");
	Tool::clearScreen();//清屏
	
	Manager manager;
	Tool::hideCursor();
    manager.GameMenu();
	Tool::hideCursor();
	manager.GameStart();
	
	thread thread_1(gameClock, ref(manager.getPlayer().gameTime));
	thread_1.detach();

	thread thread_2(playStatus, ref(manager.getPlayer()));
	thread_2.detach();
	manager.Game();
	return 0;
}