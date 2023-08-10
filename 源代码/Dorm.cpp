#include "Dorm.h"
using namespace std;
Dorm::Dorm(short x, short y)
	:Place(x, y)
{
	Bed* bed = new Bed("软绵绵的床", "躺上7小时,一觉自然醒");//类型待改
	articleArray.push_back(bed);

	ComputerGame* computerGame = new ComputerGame("快乐游戏", "疲惫的时候在虚拟世界里适当摆烂也是不错的选择喔");
	articleArray.push_back(computerGame);

}
void Dorm::printInterface(Player player) const
{
	Place::printInterface(player);
	Tool::setCursorPos(95, 0);
	cout << "宿舍";
	Tool::setCursorPos(73, 2);
	cout << "都到宿舍了还卷个der,快休息(打游戏也未尝不可)";
}
void Dorm::printPlace() const
{
	Tool::setCursorPos(80, 17);
	cout << "\033[32mЖЖЖ\033[0m";
	Tool::setCursorPos(78, 18);
	cout << "\033[32mЖ\033[0m\033[36m■■■\033[0m\033[32mЖ\033[0m";
	Tool::setCursorPos(position.X, position.Y);
	cout << "宿舍\033[36m■\033[0m\033[32mЖ\033[0m";
	Tool::setCursorPos(78, 20);
	cout << "\033[32mЖ\033[0m\033[36m■■■\033[0m\033[32mЖ\033[0m";
	Tool::setCursorPos(80, 21);
	cout << "\033[32mЖЖЖ\033[0m";
}

void Dorm::placeFunction(Player& player)
{
	normalFunction(player);
	Tool::clearScreen();
	player.setPosition(78, 19);
}
