#include "Manager.h"
using namespace std;
//对COORD重载==运算符
bool operator==(const COORD left, const COORD right)
{
	if (left.X == right.X && left.Y == right.Y)
		return true;
	else
		return false;
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

Manager::Manager()
{
	Paper* paper = new Paper("SCUT专用信纸", "用过的都说好");
	Radio* radio = new Radio("二手收音机", "不只是四六级");
	articleArray.push_back(paper);
	articleArray.push_back(radio);

	getPlayer().setName("徐坤");
	getPlayer().setGrade(GRADE_1);
	getPlayer().setAge(18);
	getPlayer().setGender(BOY);
	getPlayer().setID(114514);

	ifstream ifs;
	ifs.open("save.txt", ios::in);
	

	if (ifs.is_open() == false)
	{
		Tool::setCursorPos(144, 39);
		
		player.gameTime = 420;
		getPlayer().setHealth(100);
		getPlayer().setEnergy(100);
		getPlayer().setHunger(80);
		
		getPlayer().setMoney(15);
		getPlayer().setEmotion(80);
		getPlayer().setPosition(20, 10);
		//cout << "使用初始设置";
	}
	else
	{
		char ch;
		ifs >> ch;
		if (ifs.eof() == true)
		{
			Tool::setCursorPos(144, 39);

			player.gameTime = 420;
			getPlayer().setHealth(60);
			getPlayer().setEnergy(80);
			getPlayer().setHunger(25);

			getPlayer().setMoney(15);
			getPlayer().setEmotion(70);
			getPlayer().setPosition(20, 10);
			//cout << "使用初始设置";
			return;
		}
		ifs.clear();
		ifs.seekg(0);
		unsigned long _gameTime;
		ifs >> _gameTime;
		player.gameTime = _gameTime;
		for (int i = 0; i < 13; i++)
		{
			int _score;
			int _GPA;
			ifs >> _score; 
			ifs >> _GPA;
			player.getStatus_learning().getSubjectArray()[i].score = _score;
			player.getStatus_learning().getSubjectArray()[i].subjectGPA = (GPA)_GPA;
		}

		int _money;
		int _health;
		int _hunger;
		int _emotion;
		int _energy;
		short position_x;
		short position_y;
		ifs >> _money >> _health >> _hunger >> _emotion >> _energy >> position_x >> position_y;
		player.setMoney(_money);
		player.setHealth(_health);
		player.setHunger(_hunger);
		player.setEnergy(_energy);
		player.setEmotion(_emotion);
		player.setPosition(position_x, position_y);
	}
}
Manager::~Manager()
{

	//delete radio1;
}
bool Manager::isOutofRange(int x, int y) const
{

	if (x < 0 || y < 0 || x >= WIDTH - 1 || y >= HIGH)
		return true;
	else
		return false;
}
void Manager::showAttribute() const
{

}

void Manager::printArticle() const
{
	for (int sub = 0; sub < articleArray.size(); sub++)
	{
		if (sub < 10)
		{
			Tool::setCursorPos(11, 10 + sub);
		}
		else if (sub < 20)
		{
			Tool::setCursorPos(44, sub);
		}
		cout << articleArray[sub]->getArticleName();//打印物品名称
	}
}

void Manager::printBag() const//背包界面,在其中实现背包的操作(鼠标,是否兼容键盘再考虑)
{
	COORD pos = { 0, 0 };
	//输出基本框架
	SetConsoleCursorPosition(hOut, pos);
	cout << "|-----------------------------属  性-----------------------------|-----------------------------说明----------------------------|\n";
	cout << "|    姓名：                      性别：                          |                                                             |\n";
	cout << "|    年级：                      学号：                          |                                                             |\n";
	cout << "|                                                                |                                                             |\n";
	cout << "|                                                                |                                                             |\n";
	cout << "|    健康值：                    金钱：                          |                                                             |\n";
	cout << "|    饱食度：                    情绪：                          |                                                             |\n";
	cout << "|    精力值：                                                    |                                                             |\n";
	cout << "|                                                                |                                                             |\n";
	cout << "|-----------------------------背  包-----------------------------|                                                             |\n";
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
void Manager::bag()
{
	Tool::clearScreen();
	printBag();
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
				printBag();

				Tool::setBagOptionDefault(posStatu);
				// 实现点击使用功能
				if (posStatu >= PACKAGE_1 && posStatu <= PACKAGE_19 && packagepos == CHECK)
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
					Tool::setCursorPos(95, 17);
					cout << "使用";
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
void Manager::addToBag()
{
	switch (player.getAddArticleToBag())
	{
	case BAGNONE:
		return;
		break;
	case BAGRADIO:
	{
		//Radio* radio = new Radio("二手收音机", "不只是四六级", RADIO);
		Radio* radio = new Radio("二手收音机", "不只是四六级");
		articleArray.push_back(radio);
		break;
	}
	case COLA:
	{
		Cola* cola = new Cola("肥宅快乐水", "妹说就是0卡");
		articleArray.push_back(cola);
		break;
	}
	case BAGPAPER:
	{
		Paper* paper = new Paper("SCUT专用信纸", "用过的都说好");
		articleArray.push_back(paper);
		break;
	}
	default:
		break;
	}
	player.getAddArticleToBag() = BAGNONE;
}


void Manager::GameMenu()//待补充
{
	Tool::setCursorPos(0, 0);
	cout << "\n\n\n\n\n\n";
	cout << "\033[36m";
	cout << "                                  ■          ■        ■■■    ■■■    ■■■■■      ■■■■■      ■      ■      ■■■■■                          "
		<< "                                 ■■        ■■         ■■    ■■      ■              ■              ■      ■          ■                              "
		<< "                                ■  ■      ■  ■          ■■■■        ■              ■              ■      ■          ■                              "
		<< "                               ■    ■    ■    ■           ■■          ■■■■■      ■              ■      ■          ■                              "
		<< "                              ■      ■  ■      ■          ■■                  ■      ■              ■      ■          ■                              "
		<< "                             ■        ■■        ■         ■■                  ■      ■              ■      ■          ■                              "
		<< "                            ■          ■          ■        ■■          ■■■■■      ■■■■■      ■■■■■          ■                              ";
	cout << "\033[0m";
	Tool::setCursorPos(70, 30);
	cout << "| 开  始  游  戏 |";

	while (true)
	{
		POINT p;//鼠标点击的坐标
		CONSOLE_FONT_INFO consoleCurrentFont;//字体的信息
		GetCurrentConsoleFont(hOut, false, &consoleCurrentFont);//获取当前控制台字体信息
		if (KEY_DOWN(VK_LBUTTON))
		{
			//获取鼠标点击的位置
			GetCursorPos(&p);
			ScreenToClient(GetConsoleWindow(), &p);//将坐标转换为控制台坐标
			int x = p.x / consoleCurrentFont.dwFontSize.X;
			int y = p.y / consoleCurrentFont.dwFontSize.Y;//转换后的坐标
			if (x >= 70 && x <= 87 && y == 30)
			{
				Tool::clearScreen();
				return;
			}
		}
	}

}
void Manager::GameStart()//待修缮
{
	//第一幕：背景介绍
	cout << "\033[36m";
	string background_1 = "你是徐坤，一名刚刚从高中步入SCUT软件工程专业的大一新生.";
	Tool::setCursorPos(54, 10);
	for (auto element : background_1)
	{
		cout << element;
		Sleep(60);
	}
	Sleep(500);
	string background_2 = "怀揣着对未来的憧憬，你背井离乡，在这片校园内开启了新的征程.";
	Tool::setCursorPos(54, 12);
	for (auto element : background_2)
	{
		cout << element;
		Sleep(60);
	}
	Sleep(500);
	cout << "\033[36m";
    string background_3 = "以自己的意志，抵达自己想要的终点吧。";
	Tool::setCursorPos(54, 14);
	for (auto element : background_3)
	{
		cout << element;
		Sleep(60);
	}
	Sleep(500);
	cout << "\033[36m";
	string background_4  = "本游戏纯属虚构，如有雷同，纯属巧合";
	Tool::setCursorPos(54, 18);
	for (auto element : background_4)
	{
		cout << element;
		Sleep(60);
	}
	Sleep(5000);
	Tool::clearScreen();
	//第二幕：游戏指南
	Tool::hideCursor();
	Tool::setCursorPos(70, 3);
	cout << "\033[36m";
	cout << "游 戏 指 南";
	Tool::setCursorPos(58, 6);
	cout << "指南1：mySCUT地点及其功能" << endl;
	Tool::setCursorPos(58, 8);
	cout << "天桥：生活区和教学区的转换处" << endl;
	Tool::setCursorPos(58, 10);
	cout << "生活区部分：" << endl;
	Tool::setCursorPos(58, 11);
	cout << "\033[36m";
	cout << "宿舍：睡觉（补充精力值）、打游戏" << endl;
	Tool::setCursorPos(58, 12);
	cout << "体育馆：体育锻炼（补充健康值）" << endl;
	Tool::setCursorPos(58, 13);
	cout << "饭堂：吃饭（补充饱食度）" << endl;
	Tool::setCursorPos(58, 14);
	cout << "超市：购买物品" << endl;
	Tool::setCursorPos(58, 15);
	cout << "医院：接受治疗（恢复健康值）" << endl;
	Tool::setCursorPos(58, 17);
	cout << "\033[36m";
	cout << "教学区部分：（所有活动都可以提高学业水平）" << endl;
	Tool::setCursorPos(58, 18);
	cout << "课室：上课、参加竞赛、参加考试" << endl;
	Tool::setCursorPos(58, 19);
	cout << "图书馆：自主学习" << endl;
	Tool::setCursorPos(58, 20);
	cout << "实验室：做实验" << endl;
	Tool::setCursorPos(58, 22);
	cout << "\033[36m";
	cout << "指南2：右下方的课表是徐坤的To do list" << endl;
	Tool::setCursorPos(58, 24);
	cout << "指南3：请密切关注徐坤的健康值、精力值、饱食度和情绪值";
	Tool::setCursorPos(65, 25);
	cout << "如果这些值处于不妙的区间的话，可能触发特殊结局" << endl;
	Tool::setCursorPos(58, 27);
	cout << "指南4：请密切关注徐坤的期末考试";
	Tool::setCursorPos(58, 29);
	cout << "指南5：通过方向键控制角色的移动，鼠标的点击来选择操作,退出会自动存档";
	Tool::setCursorPos(65, 30);	
	cout << "按P键打开背包，按S键存档，按esc退出, 按delete键会删除存档";
	cout << "\033[0m";


	Tool::setCursorPos(70, 36);
	cout << "| 按Enter键开始游戏 |";
	while(true)
	{
		if (KEY_DOWN(VK_RETURN))
		{
			Tool::clearScreen();
			break;
		}
	}
}

void Manager::Game()
{
	bool isContinue = true;//游戏是否进行
	bool isShowingBag = false;//背包是否正在显示

	while (isContinue == true)
	{
		if (KEY_DOWN(VK_LEFT))//左方向键
		{
			Tool::clearScreen();
			if (isOutofRange(player.getPosition().X - 1, player.getPosition().Y) == false)
				player.GoLeft();
		}
		else if (KEY_DOWN(VK_RIGHT))//右方向键
		{
			Tool::clearScreen();
			if (isOutofRange(player.getPosition().X + 1, player.getPosition().Y) == false)
				player.GoRight();
		}
		else if (KEY_DOWN(VK_UP))//上方向键
		{
			Tool::clearScreen();
			if (isOutofRange(player.getPosition().X, player.getPosition().Y - 1) == false)
				player.GoUp();
		}
		else if (KEY_DOWN(VK_DOWN))//下方向键
		{
			Tool::clearScreen();
			if (isOutofRange(player.getPosition().X, player.getPosition().Y + 1) == false)
				player.GoDown();
		}
		else if (KEY_DOWN(VK_ESCAPE))//esc键
		{
			Tool::clearScreen();
			Sleep(100);
			COORD pos = { 65, 18 };
			bool isExcuted = false;
			while (true)
			{
				if (isExcuted == false)
				{
					SetConsoleCursorPosition(hOut, pos);
					cout << "-----------------------------";
					++pos.Y;
					SetConsoleCursorPosition(hOut, pos);
					cout << "|    您确定要退出游戏吗?    |";
					++pos.Y;
					SetConsoleCursorPosition(hOut, pos);
					cout << "| (Enter 退出)   (Esc 返回) |";
					++pos.Y;
					SetConsoleCursorPosition(hOut, pos);
					cout << "-----------------------------";
					isExcuted = true;
				}
				if (KEY_DOWN(VK_RETURN))//回车键
				{
					return;
				}
				else if (KEY_DOWN(VK_ESCAPE))
				{
					saveGame();
					Tool::clearScreen();
					break;
					//return;
				}
				Sleep(100);
			}
			//break;
		}
		else if (KEY_DOWN('P'))//P键
		{
			//使按p键显示或关闭背包界面
			bag();//进入背包界面
			Tool::clearScreen();
		}
		else if (KEY_DOWN('S'))//S键保存
		{
			saveGame();
		}
		else if (KEY_DOWN(VK_DELETE))
		{
			deleteFile();
		}
		inPlace();
		addToBag();
		printWhole();//打印人物和地图等
		Sleep(100);//防止闪屏和连击
		if (player.gameTime % 5760 == 480)
		{
			player.setMoney(player.getMoney() + 15);
			player.gameTime += 1;
		}
		if (player.getHealth() <= 0)//健康值为0, 死亡结局
		{
			Tool::clearScreen();
			Tool::setCursorPos(50, 16);
			cout << "走在学校的水泥路上, 你的双眼愈发模糊, 不知什么时候你倒下了, 再也没有醒来...";
			return;
		}

		if (player.getEnergy() <= 0)//精神值为0, 猝死结局
		{
			Tool::clearScreen();
			Tool::setCursorPos(50, 16);
			cout << "行走在代码的山间, 突然间一片黑暗充斥了你的视线, 你失去了身体的掌控权, 倒在了键盘之上...";
			return;
		}

		if (player.getEmotion() <= 0)//情绪值为0, 抑郁结局
		{
			Tool::clearScreen();
			Tool::setCursorPos(50, 16);
			cout << "长期的压抑压得你步入了抑郁的深渊,不得已之下你选择了休学...";
			return;
		}

		if (player.gameTime / 5760 == 3)
		{
			GameEnd();
			return;
		}
	}

}

void Manager::GameEnd()
{
	Tool::clearScreen();

	int FinalGPA = getPlayer().getStatus_learning().calTotalGPA(0, 12);
	if (FinalGPA >= 32) //学业等级为A等
	{
		Tool::setCursorPos(60, 13);
		cout << "历尽艰辛，你终于获取了保送研究生资格。请问你选择继续深造还是参加工作?"; //对A等生，要么保研、要么工作
		Tool::setCursorPos(70, 25);
		cout << "| 保研深造 |" << endl;
		Tool::setCursorPos(90, 25);
		cout << "| 进入职场 |" << endl;

		while (true)
		{
			POINT p;//鼠标点击的坐标
			CONSOLE_FONT_INFO consoleCurrentFont;//字体的信息
			GetCurrentConsoleFont(hOut, false, &consoleCurrentFont);//获取当前控制台字体信息
			if (KEY_DOWN(VK_LBUTTON))
			{
				GetCursorPos(&p);
				ScreenToClient(GetConsoleWindow(), &p);//将坐标转换为控制台坐标
				int x = p.x / consoleCurrentFont.dwFontSize.X;
				int y = p.y / consoleCurrentFont.dwFontSize.Y;//转换后的坐标
				if (x >= 70 && x <= 81 && y == 25)
				{
					Tool::clearScreen();
					Tool::setCursorPos(50, 16);
					cout << "恭喜你踏入了科研的殿堂，开启新的学习之旅...";
				}
				else if (x >= 90 && x <= 101 && y == 25)
				{
					Tool::clearScreen();
					Tool::setCursorPos(50, 16);
					cout << "在秋季招聘中，你表现优异，同时收到了5份offer，你经过综合评估选择了一家大公司，开启了新的人生阶段...";
				}
			}
		}
	}
	else if (FinalGPA >= 28 && FinalGPA < 32) //学业等级为B等
	{
		Tool::setCursorPos(60, 13);//对B等生，要么考研、要么工作
		cout << "面前有两条路，一条是走考研的独木桥，一条是闯工作的腊子口。你选择？"; //对A等生，要么保研、要么工作
		Tool::setCursorPos(70, 25);
		cout << "| 奋勇考研 |" << endl;
		Tool::setCursorPos(90, 25);
		cout << "| 进入职场 |" << endl;

		while (true)
		{
			POINT p;//鼠标点击的坐标
			CONSOLE_FONT_INFO consoleCurrentFont;//字体的信息
			GetCurrentConsoleFont(hOut, false, &consoleCurrentFont);//获取当前控制台字体信息
			if (KEY_DOWN(VK_LBUTTON))
			{
				GetCursorPos(&p);
				ScreenToClient(GetConsoleWindow(), &p);//将坐标转换为控制台坐标
				int x = p.x / consoleCurrentFont.dwFontSize.X;
				int y = p.y / consoleCurrentFont.dwFontSize.Y;//转换后的坐标
				if (x >= 70 && x <= 81 && y == 25)
				{
					Tool::clearScreen();
					Tool::setCursorPos(50, 16);
					if (rand() % 2 == 1)
					{
						cout << "恭喜你历尽艰辛，终于踏入了科研的殿堂，开启新的学习之旅...";
					}
					else
					{
						cout << "可惜的是考研失利，但你很快走出了考研失败的阴影，坐上了春招的末班车，开启了职场的新人生...";
					}
				}
				else if (x >= 90 && x <= 101 && y == 25)
				{
					Tool::clearScreen();
					Tool::setCursorPos(50, 16);
					cout << "在秋季招聘中，你表现良好，最终选择了一家中小企业，开启了新的人生阶段...";
				}
			}
		}
	}
	else if (FinalGPA >= 24 && FinalGPA < 28) //学业等级为C等
	{
		Tool::clearScreen();
		Tool::setCursorPos(50, 16);
		cout << "不起眼的成绩使得你升学无望，经过磕磕绊绊的校招，你终于勉强找到了工作，开启了新的生活..." << endl; //对C等生，直接工作
	}
	else
	{
		Tool::clearScreen();
		Tool::setCursorPos(50, 16);
		cout << "很遗憾，你的总学分并没有达到毕业的要求，无法毕业。" << endl; //对D等生，无法毕业
	}
}

void Manager::printWhole() const
{
	switch (getWhichMap())
	{
	case LIVINGAREA:
		livingArea.printMap();
		break;
	case TEACHINGAREA:
		teachingArea.printMap();
		break;
	default:
		break;
	}
	player.printPlayer();//打印人物
	showTime();//显示时间
	showTask();//显示任务栏
}

int Manager::isPlace() const
{
	switch (whichMap)
	{
	case LIVINGAREA:
		for (int sub = 0; sub < livingArea.getPlaceArray().size(); sub++)
		{
			if (livingArea.getPlaceArray()[sub]->getPostion() == player.getPosition())
			{
				return sub;
			}
		}
		break;
	case TEACHINGAREA:
		for (int sub = 0; sub < teachingArea.getPlaceArray().size(); sub++)
		{
			if (teachingArea.getPlaceArray()[sub]->getPostion() == player.getPosition())
			{
				return sub;
			}
		}
		break;
	default:
		break;
	}
	return -1;
}

void Manager::inPlace()
{
	int numPlace = isPlace();
	if (numPlace == -1)
		return;
	else if (numPlace == 0)//Bridge,转换地图类型
	{
		if (whichMap == LIVINGAREA)
		{
			whichMap = TEACHINGAREA;

		}
		else
			whichMap = LIVINGAREA;
	}
	switch (getWhichMap())
	{
	case LIVINGAREA:
		livingArea.getPlaceArray()[numPlace]->placeFunction(player);
		break;
	case TEACHINGAREA:
		teachingArea.getPlaceArray()[numPlace]->placeFunction(player);
		break;
	default:
		break;
	}
}

void Manager::showTime() const
{
	const unsigned long& grade = player.gameTime / 5760;
	const unsigned long& season = player.gameTime / 1440 % 4;
	const unsigned long& hour = player.gameTime / 60 % 24;
	const unsigned long& minute = player.gameTime % 60;
	Tool::setCursorPos(140, 1);
	switch (grade)
	{
	case 0:
		cout << "大一 ";
		break;
	case 1:
		cout << "大二 ";
		break;
	case 2:
		cout << "大三 ";
		break;
	}

	switch (season)
	{
	case 0:
		cout << "秋 ";
		break;
	case 1:
		cout << "冬 ";
		break;
	case 2:
		cout << "春 ";
		break;
	case 3:
		cout << "夏 ";
		break;
	}
	cout << "  " << hour << ':' << minute;
}

void Manager::showTask() const
{
	//130 * 22
	int p = 22;
	Tool::setCursorPos(130, 22);
	cout << "\033[36m";
	cout << "------------课  表------------";
	for (int i = 0; i < 17; i++)
	{
		Tool::setCursorPos(130, ++p);
		cout << "|";
	}

	//加上各个作息
	switch (player.gameTime / 5760)
	{
	case 0:
		switch (player.gameTime / 1440 % 4)
		{
		case 0://大一秋
			Tool::setCursorPos(133, 24);
			cout << "9:00   C++课程 -> 教室";
			Tool::setCursorPos(133, 28);
			cout << "14:00  数学分析 -> 教室";
			break;
		case 1://大一冬
			Tool::setCursorPos(133, 24);
			cout << "9:00   线性代数 -> 教室";
			Tool::setCursorPos(133, 26);
			cout << "14:00  大学物理 -> 教室";
			break;
		case 2://大一春
			Tool::setCursorPos(133, 24);
			cout << "9:00   大学英语 -> 教室";
			Tool::setCursorPos(133, 26);
			cout << "14:00  百团大战 -> 教室";
			Tool::setCursorPos(133, 28);
			cout << "14:00  概率论 -> 教室";
			break;
		case 3://大一夏
			Tool::setCursorPos(133, 24);
			cout << "14:00  期末考试 -> 教室";
			break;
		}
		break;
	case 1:
		switch (player.gameTime / 1440 % 4)
		{
		case 0://大二秋
			Tool::setCursorPos(133, 24);
			cout << "9:00   数据结构 -> 教室";
			Tool::setCursorPos(133, 26);
			cout << "14:00  离散数学 -> 教室";
			break;
		case 1://大二冬
			Tool::setCursorPos(133, 24);
			cout << "9:00   实验课 -> 实验室";
			Tool::setCursorPos(133, 26);
			cout << "14:00  程序设计竞赛 -> 教室";
			Tool::setCursorPos(133, 28);
			cout << "19:00  操作系统 -> 教室";
			break;
		case 2://大二春
			Tool::setCursorPos(133, 24);
			cout << "9:00   计组 -> 教室";
			Tool::setCursorPos(133, 26);
			cout << "14:00  实验课 -> 实验室";
			break;
		case 3://大二夏
			Tool::setCursorPos(133, 24);
			cout << "14:00  期末考试 -> 教室";
			break;
		}
		break;
	case 2:
		switch (player.gameTime / 1440 % 4)
		{
		case 0://大三秋
			Tool::setCursorPos(133, 24);
			cout << "9:00   编译原理 -> 教室";
			Tool::setCursorPos(133, 26);
			cout << "14:00  实验课 -> 实验室";
			break;
		case 1://大三冬
			Tool::setCursorPos(133, 24);
			cout << "9:00   实验课 -> 实验室";
			Tool::setCursorPos(133, 26);
			cout << "14:00  计网 -> 教室";
			break;
		case 2://大三春
			Tool::setCursorPos(133, 24);
			cout << "9:00   大数据开发 -> 教室";
			Tool::setCursorPos(133, 26);
			cout << "14:00  程序设计竞赛 -> 教室";
			break;
		case 3://大三夏
			Tool::setCursorPos(133, 24);
			cout << "14:00   期末考试 -> 教室";
			break;
		}
		break;
	}

	cout << "\033[0m";
}

void Manager::saveGame()
{
	ofstream ofs;
	ofs.open("save.txt", ios::out);
	//时间
	ofs << player.gameTime << endl;
	//先存成绩
	for (int i = 0; i < player.getStatus_learning().getSubjectArray().size(); i++)
	{
		ofs << player.getStatus_learning().getSubjectArray()[i].score << endl;
		ofs << player.getStatus_learning().getSubjectArray()[i].subjectGPA << endl;
	}
	//属性
	ofs << player.getMoney() << endl
		<< player.getHealth() << endl
		<< player.getHunger() << endl
		<< player.getEmotion() << endl
		<< player.getEnergy() << endl
		<< player.getPosition().X << endl 
		<< player.getPosition().Y << endl;
}

void Manager::deleteFile()
{
	ofstream ofs;
	ofs.open("save.txt", ios::out);
	ofs.close();
}
