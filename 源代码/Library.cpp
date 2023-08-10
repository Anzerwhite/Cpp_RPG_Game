#include "Library.h"
using namespace std;
Library::Library(short x, short y)
	:Place(x, y)
{
}
void Library::printInterface(Player player) const
{
	Place::printInterface(player);
	Tool::setCursorPos(95, 0);
	cout << "图书馆";
	Tool::setCursorPos(73, 2);
	cout << "在图书馆当然要安安静静地卷啦()";
}
void Library::printPlace() const
{
	Tool::setCursorPos(96, 9);
	cout << "\033[32mЖ\033[33m■■■\033[32mЖ";
	Tool::setCursorPos(96, 10);
	cout << "\033[33m■\033[0m图书馆\033[33m■";
	Tool::setCursorPos(96, 11);
	cout << "\033[32mЖ\033[33m■  ■\033[32mЖ\033[0m";
}

void Library::placeFunction(Player& player)
{
	Tool::clearScreen();
	printInterface(player);
	Tool::setCursorPos(81, 10);
	cout << "正在自习中...";
	Sleep(3000);
	Tool::setCursorPos(81, 10);
	cout << "自习结束，将自动离开";
	Sleep(2000);
	switch (player.gameTime / 5760)
	{
	case GRADE_1:
		for (int i = 0; i < 6; i++)
		{
			player.getStatus_learning().getSubjectArray()[i].score += 2;
		}
		break;
	case GRADE_2:
		for (int i = 6; i < 10; i++)
		{
			player.getStatus_learning().getSubjectArray()[i].score += 2;
		}
		break;
	case GRADE_3:
		for (int i = 10; i < 13; i++)
		{
			player.getStatus_learning().getSubjectArray()[i].score += 2;
		}
		break;
	default:
		break;
	}
	player.setHunger(player.getHunger() - 7);
	player.setEnergy(player.getEnergy() - 7);
	player.setEmotion(player.getEmotion() - 2);
	player.gameTime += 60;
	Tool::clearScreen();
	player.setPosition(100, 11);
}
