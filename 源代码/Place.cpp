#include "Place.h"
using std::cout;
Place::Place(short x, short y)
{
	position.X = x;
	position.Y = y;
}
Place::~Place()
{
}

void Place::printInterface(Player player) const
{
	COORD pos = { 0, 0 };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//输出基本框架
	SetConsoleCursorPosition(hOut, pos);
	cout << "|-----------------------------属  性-----------------------------|-----------------------------地点----------------------------|\n";
	cout << "|    姓名：                      性别：                          |                                                             |\n";
	cout << "|    年级：                      学号：                          |                                                             |\n";
	cout << "|                                                                |                                                             |\n";
	cout << "|                                                                |-----------------------------说明----------------------------|\n";
	cout << "|    健康值：                    金钱：                          |                                                             |\n";
	cout << "|    饱食度：                    情绪：                          |                                                             |\n";
	cout << "|    精力值：                                                    |                                                             |\n";
	cout << "|                                                                |                                                             |\n";
	cout << "|-----------------------------菜  单-----------------------------|                                                             |\n";
	//0 * 10 -- 32 * 10     11               // 33 * 10 -- 65 * 10
	cout << "|                               ||                               |                                                             |\n";
	cout << "|                               ||                               |                                                             |\n";
	cout << "|                               ||                               |                                                             |\n";
	cout << "|                               ||                               |                                                             |\n";
	cout << "|                               ||                               |                                                             |\n";
	cout << "|                               ||                               |                                                             |\n";
	cout << "|                               ||                               |                                                             |\n";
	cout << "|                               ||                               |                                                             |\n";
	cout << "|                               ||                               |                                                             |\n";
	cout << "|                               ||                               |                             退出                            |\n";
	//0 * 19 -- 32 * 19                    // 33 * 10 -- 65 * 19  如何实现点击高亮
	cout << "|----------------------------------------------------------------|-------------------------------------------------------------|";
	short& x = pos.X;
	short& y = pos.Y;//坐标,方便操作
	//指定位置输出名字
	x += 13;  y += 1;
	SetConsoleCursorPosition(hOut, pos);
	cout << player.getName();

	//指定位置输出年级
	y += 1;
	SetConsoleCursorPosition(hOut, pos);
	cout << player.getGradeName();

	////指定位置输出生命值
	//y += 2;
	//SetConsoleCursorPosition(hOut, pos);
	//cout << player.getHP();

	//指定位置输出健康值
	y += 3;
	SetConsoleCursorPosition(hOut, pos);
	cout << player.getHealth();

	//指定位置输出饱食度
	y += 1;
	SetConsoleCursorPosition(hOut, pos);
	cout << player.getHunger();

	//指定位置输出精力值
	y += 1;
	SetConsoleCursorPosition(hOut, pos);
	cout << player.getEnergy();

	//指定位置输出性别
	x = 40; y = 1;
	SetConsoleCursorPosition(hOut, pos);
	cout << player.getGenderName();

	//指定位置输出学号
	y += 1;
	SetConsoleCursorPosition(hOut, pos);
	cout << player.getID();

	////指定位置输出家境
	//y += 2;
	//SetConsoleCursorPosition(hOut, pos);
	//cout << player.getStatus_familyName();
	
	//指定位置输出金钱
	y += 3;
	SetConsoleCursorPosition(hOut, pos);
	cout << "￥" << player.getMoney();

	//指定位置输出情绪
	y += 1;
	SetConsoleCursorPosition(hOut, pos);
	cout << player.getEmotion();

	//输出物品
	printArticle();
}

void Place::printArticle() const
{
	for (int sub = 0; sub < articleArray.size(); sub++)
	{
		if (sub < 10)
		{
			Tool::setCursorPos(7, 10 + sub);
		}
		else if (sub < 20)
		{
			Tool::setCursorPos(40, sub);
		}
		cout << articleArray[sub]->getArticleName();//打印物品名称
	}
}

void Place::normalFunction(Player& player)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Tool::clearScreen();
	printInterface(player);
	Sleep(100);//防止连击与闪屏
	//对背包进行操作
	BagOption posStatu = PACKAGE_1;//鼠标点击的位置
	while (true)
	{
		POINT p;//鼠标点击的坐标
		CONSOLE_FONT_INFO consoleCurrentFont;//字体的信息
		GetCurrentConsoleFont(hOut, false, &consoleCurrentFont);//获取当前控制台字体信息
		if (KEY_DOWN(VK_LBUTTON))//鼠标左键按下
		{
			//获取鼠标点击的位置
			GetCursorPos(&p);
			ScreenToClient(GetConsoleWindow(), &p);//将坐标转换为控制台坐标
			int x = p.x / consoleCurrentFont.dwFontSize.X;
			int y = p.y / consoleCurrentFont.dwFontSize.Y;//转换后的坐标
			BagOption packagepos = Tool::GetBagOptionPos(x, y);
			if (packagepos != NOPACKAGE && packagepos <= articleArray.size() || packagepos >= CHECK)//判断是否
			{
				Tool::clearScreen();
				printInterface(player);
				Tool::setBagOptionDefault(posStatu);

				// 实现点击购买功能
				if(posStatu >= PACKAGE_1 && posStatu <= PACKAGE_19 && packagepos == CHECK)
				{
					articleArray[posStatu - 1]->articleFunction(player);
				}
				posStatu = packagepos;
				Tool::setBagOptionHighLight(posStatu);
				switch (posStatu)
				{
				case NOPACKAGE:
					break;
				case PACKAGE_1:
				case PACKAGE_2:
				case PACKAGE_3:
				case PACKAGE_4:
				case PACKAGE_5:
				case PACKAGE_6:
				case PACKAGE_7:
				case PACKAGE_8:
				case PACKAGE_9:
				case PACKAGE_10:
				case PACKAGE_11:
				case PACKAGE_12:
				case PACKAGE_13:
				case PACKAGE_14:
				case PACKAGE_15:
				case PACKAGE_16:
				case PACKAGE_17:
				case PACKAGE_18:
				case PACKAGE_19:
				case PACKAGE_20:
					articleArray[posStatu - 1]->printExplain();
					break;
				case ESCBAG:
					Sleep(100);
					return;
					break;
				default:
					break;
				}
			}
		}
		else if (KEY_DOWN('P'))//按下P也能退出背包界面
		{
			return;
		}
		Sleep(100);//防止连击与闪屏
	}
}
