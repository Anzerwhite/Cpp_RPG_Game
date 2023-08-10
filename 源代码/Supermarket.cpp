#include "Supermarket.h"
using namespace std;
Supermarket::Supermarket(short x, short y)
	:Place(x, y)
{
	Cola* cola = new Cola("肥宅快乐水", "妹说就是0卡");
	Paper* paper = new Paper("SCUT专用信纸", "用过的都说好");
	Radio* radio = new Radio("二手收音机", "不只是四六级");
	articleArray.push_back(cola);
	articleArray.push_back(paper);
	articleArray.push_back(radio);
}
void Supermarket::printInterface(Player player) const
{
	Place::printInterface(player);
	Tool::setCursorPos(95, 0);
	cout << "西亚";
	Tool::setCursorPos(73, 2);
	cout << "欢迎来到SCUT大超市，你可以根据自身情况购买物品";

}
void Supermarket::printPlace() const
{
	Tool::setCursorPos(36, 8);
	cout << "\033[32mЖ\033[0m\033[34m■  ■\033[0m\033[32mЖ\033[0m";
	Tool::setCursorPos(36, 9);
	cout << "\033[34m■■■■■";
	Tool::setCursorPos(36, 10);
	cout << "■\033[0m超  市\033[34m■";
	Tool::setCursorPos(36, 11);
	cout << "■\033[32mЖ  Ж\033[34m■\033[0m";
}

void Supermarket::placeFunction(Player& player)
{
	normalFunction(player);
	Tool::clearScreen();
	player.setPosition(40, 11);
}
