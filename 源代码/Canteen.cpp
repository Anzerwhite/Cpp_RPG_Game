#include "Canteen.h"
using namespace std;
Canteen::Canteen(short x, short y)
	:Place(x, y)
{
	//任务:制作物品表,在指定位置输出
	//问题1:如何格式化输出信息
	StonepotRice* stonepotRice = new StonepotRice("石锅饭", "香喷喷的石锅饭, 你的不二之选!");//实例化一个石锅饭的选项
	articleArray.push_back(stonepotRice);
	//油饼 + 纯露仁 OilBing            小菜
	OilBing* oilBing = new OilBing("油饼 + 纯露仁", "当油饼遇上纯露仁, 舌尖上的清爽~");
	articleArray.push_back(oilBing);
	//蒸德食泥鸭 + 梅素汁  Duck        中
	Duck* duck = new Duck("蒸德食泥鸭 + 梅素汁", "肥美的蒸鸭入口即化, 酸甜的梅素汁解去所有烦恼~");
	articleArray.push_back(duck);
	//蒸乌鱼 + 香翅捞饭    BlackFish   大
	BlackFish* blackFish = new BlackFish("蒸乌鱼 + 香翅捞饭", "一个字,就是下饭!");
	articleArray.push_back(blackFish);
	//德国鸡腿堡    Hamburger          中
	Hamburger* hamburger = new Hamburger("德国鸡腿堡", "来自西方的手艺, 体验异域的风情!");
	articleArray.push_back(hamburger);
	//云南过桥米线  BridgeNoodles      中
	BridgeNoodles* bridgeNoodles = new BridgeNoodles("云南过桥米线", "吃完后过天桥将不再吃力!");
	articleArray.push_back(bridgeNoodles);
	//正宗隆江猪脚饭 PigLegRice       大
	PigLegRice* pigLegRice = new PigLegRice("正宗隆江猪脚饭", "你就说正不正宗吧");
	articleArray.push_back(pigLegRice);

}
Canteen::~Canteen()
{
}
void Canteen::printInterface(Player player) const
{
	Place::printInterface(player);
	Tool::setCursorPos(95, 0);
	cout << "饭堂";
	Tool::setCursorPos(73, 2);
	cout << "欢迎来到SCUT饭堂，你想吃的都在这里!";
}
void Canteen::printPlace() const
{
	Tool::setCursorPos(116, 29);
	cout << "\033[32mЖ\033[33m■  ■\033[32mЖ";
	Tool::setCursorPos(116, 30);
	cout << "\033[33m■\033[0m饭  堂\033[33m■";
	Tool::setCursorPos(116, 31);
	cout << "\033[32mЖ\033[33m■■■\033[32mЖ\033[0m";
}

void Canteen::placeFunction(Player& player)
{
	normalFunction(player);
	Tool::clearScreen();
	player.setPosition(120, 29);
}
