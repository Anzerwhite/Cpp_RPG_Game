#include "Gym.h"
using namespace std;
Gym::Gym(short x, short y)
	:Place(x, y)
{
}
void Gym::printInterface(Player player) const
{
	Place::printInterface(player);
	Tool::setCursorPos(95, 0);
	cout << "健身房";
	Tool::setCursorPos(73, 2);
	cout << "猛男栖息地,竹杆进去木桶出来!";
}
void Gym::printPlace() const
{
	Tool::setCursorPos(38, 28);
	cout << "\033[32mЖ  Ж";
	Tool::setCursorPos(36, 29);
	cout << "Ж\033[31m■  ■\033[32mЖ";
	Tool::setCursorPos(36, 30);
	cout << "\033[31m■\033[0m健身房\033[31m■";
	Tool::setCursorPos(36, 31);
	cout << "■■■■■\033[0m";
}

void Gym::placeFunction(Player& player)
{
	Tool::clearScreen();
	printInterface(player);
	Tool::setCursorPos(81, 10);
	cout << "正在锻炼中...";
	Sleep(3000);
	Tool::setCursorPos(81, 10);
	cout << "锻炼结束，将自动离开";
	Sleep(2000);
	player.setHealth(player.getHealth() + 5);
	player.setHunger(player.getHunger() - 7);
	player.setEnergy(player.getEnergy() - 5);
	player.setEmotion(player.getEmotion() + 5);
	player.gameTime += 60;
	Tool::clearScreen();
	player.setPosition(40, 29);
}
