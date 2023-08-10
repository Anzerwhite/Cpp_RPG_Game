#include "Bridge.h"
#include"Tool.h"
using namespace std;
Bridge::Bridge(short x, short y)
	:Place(x, y)
{

}
void Bridge::printPlace() const
{
	Tool::setCursorPos(position.X, position.Y - 1);
	cout << "\033[31m■";
	Tool::setCursorPos(position.X, position.Y + 1);
	cout << "■\033[0m";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	Tool::setColor(DARKGREY, WHITE);
	cout << "桥";
	Tool::setDefaultColor();
	
}

void Bridge::placeFunction(Player& player)
{
	//改变坐标，并防止多次访问
	if (player.getPosition().X == 158)
	{
		player.setPosition(2, 19);
	}
	else if (player.getPosition().X == 0)
	{
		player.setPosition(156, 19);
	}
}

