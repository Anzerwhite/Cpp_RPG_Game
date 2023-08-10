#include "Hospital.h"
using namespace std;
Hospital::Hospital(short x, short y)
	:Place(x, y)
{
}
void Hospital::printInterface(Player player) const
{
	Place::printInterface(player);
	Tool::setCursorPos(95, 0);
	cout << "医院";
	Tool::setCursorPos(73, 2);
	cout << "救死扶伤之地, 治疗每一位受伤的SCUTer";
}
void Hospital::printPlace() const
{
	Tool::setCursorPos(120, 6);
	cout << "◆";
	Tool::setCursorPos(118, 7);
	cout << "■\033[31m十\033[0m■";
	Tool::setCursorPos(120, 8);
	cout << "■";
	Tool::setCursorPos(116, 9);
	cout << "■■■■■";
	Tool::setCursorPos(116, 10);
	cout << "■医  院■";
	Tool::setCursorPos(116, 11);
	cout << "■■  ■■";
	Tool::setCursorPos(118, 12);
	cout << "\033[32mЖ  Ж\033[0m";
}

void Hospital::placeFunction(Player& player)
{
	Tool::clearScreen();
	printInterface(player);
	if(player.getHealth() >= 80)
	{
		Tool::setCursorPos(77, 8);
		cout << "您的身体状况良好，祝君健康！";
	}
	else
	{
		Tool::setCursorPos(77, 8);
		cout << "您的身体状况不佳，正在进行治疗...";
		Sleep(3000);
		Tool::setCursorPos(77, 8);
		cout << "已完成治疗!                      ";
		player.gameTime += 60;
		player.setHealth(player.getHealth() + 10);
		player.setEmotion(player.getEmotion() - 10);
	}
	Sleep(2000);//防止连击与闪屏
	Tool::clearScreen();
	player.setPosition(120, 11);
}
