#include "Lab.h"
using namespace std;
Lab::Lab(short x, short y)
	:Place(x, y)
{
}
void Lab::printInterface(Player player) const
{
	Place::printInterface(player);
	Tool::setCursorPos(95, 0);
	cout << "实验室";
	Tool::setCursorPos(73, 2);
	cout << "第二个教室, 科研成果的诞生地";
}
void Lab::printPlace() const
{
	Tool::setCursorPos(38, 17);
	cout << "\033[32mЖ\033[36m■\033[32mЖ";
	Tool::setCursorPos(38, 18);
	cout << "\033[36m■\033[0m实\033[36m■\033[32mЖ";
	Tool::setCursorPos(38, 19);
	cout << "\033[36m■\033[0m验";
	Tool::setCursorPos(38, 20);
	cout << "\033[36m■\033[0m室\033[36m■\033[32mЖ";
	Tool::setCursorPos(38, 21);
	cout << "\033[32mЖ\033[36m■\033[32mЖ\033[0m";
}

void Lab::placeFunction(Player& player)
{
	Tool::clearScreen();
	printInterface(player);

	
	if ((player.gameTime >= 7735 && player.gameTime <= 7750) || (player.gameTime >= 9475 && player.gameTime <= 9490))
	{
		Tool::setCursorPos(77, 8);
		cout << "本次实验内容是: 数据结构和计算机组成原理 ";
		Tool::setCursorPos(77, 10);
		cout << "正在实验中...";
		Sleep(3000);
		Tool::setCursorPos(77, 10);
		cout << "叮叮叮,实验结束,将自动离开实验室";
		player.getStatus_learning().getSubjectArray()[6].score += 5;
		player.getStatus_learning().getSubjectArray()[9].score += 5;
		Sleep(2000);//防止连击与闪屏
		player.gameTime += 180;
		player.setHunger(player.getHunger() - 20);
		player.setEnergy(player.getEnergy() - 20);
		player.setEmotion(player.getEmotion() - 10);
	}
	else if ((player.gameTime >= 13495 && player.gameTime <= 13510) || (player.gameTime >= 12355 && player.gameTime <= 12370))
	{
		Tool::setCursorPos(77, 8);
		cout << "本次实验内容是: 编译原理和大数据开发";
		Tool::setCursorPos(77, 10);
		cout << "正在实验中...";
		Sleep(3000);
		Tool::setCursorPos(77, 10);
		cout << "叮叮叮,实验结束,将自动离开实验室";
		player.getStatus_learning().getSubjectArray()[10].score += 5;
		player.getStatus_learning().getSubjectArray()[12].score += 5;
		Sleep(2000);//防止连击与闪屏
		player.gameTime += 180;
		player.setHunger(player.getHunger() - 20);
		player.setEnergy(player.getEnergy() - 20);
		player.setEmotion(player.getEmotion() - 10);
	}
	else
	{
		Tool::setCursorPos(77, 8);
		cout << "当前时间段为研究生实验时间，不对外开放 ";
		Sleep(2000);//防止连击与闪屏
	}
	Tool::clearScreen();
	player.setPosition(42, 19);

}
