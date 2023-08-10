#include "Classroom.h"
using namespace std;
Classroom::Classroom(short x, short y)
	:Place(x, y)
{
}
void Classroom::printInterface(Player player) const
{
	Place::printInterface(player);
	Tool::setCursorPos(95, 0);
	cout << "教室";
	Tool::setCursorPos(73, 2);
	cout << "这里是教室,沐浴知识的圣地";
}
void Classroom::printPlace() const
{
	Tool::setCursorPos(98, 29);
	cout << "\033[32mЖ  Ж\033[0m";
	Tool::setCursorPos(98, 30);
	cout << "\033[36m■\033[0m教\033[36m■\033[0m";
	Tool::setCursorPos(98, 31);
	cout << "\033[36m■\033[0m室\033[36m■";
	Tool::setCursorPos(98, 32);
	cout << "■■■\033[0m";
}

void Classroom::placeFunction(Player& player)
{
	if ((player.gameTime <= 8040 && player.gameTime >= 8025) || (player.gameTime <= 15240 && player.gameTime >= 15225))
		olympic(player);
	else if (player.gameTime % 5760 >= 5150 && player.gameTime % 5760 <= 5170)
		examination(player);
	else
		havingClass(player);
	Tool::clearScreen();
	player.setPosition(100, 29);
}

void Classroom::havingClass(Player& player)
{
	int classNum = player.getClass().first;//课程名称(代号)
	unsigned long classTime = player.getClass().second;//课程时间

	if (player.gameTime <= classTime && player.gameTime >= classTime - 10)
	{
		printClassMessage(player, classNum);
		player.getStatus_learning().getSubjectArray()[classNum].score += 25;
		player.setEmotion(player.getEmotion() - 5);
	}
	else if (player.gameTime <= classTime + 60 && player.gameTime > classTime)
	{
		printClassMessage(player, classNum);
		player.getStatus_learning().getSubjectArray()[classNum].score += 10;
	}
	else//非上课时间
	{
		printInterface(player);
		Tool::setCursorPos(77, 8);
		cout << "非上课时间，暂不开放";
		Sleep(2000);//防止连击与闪屏
		return;
	}
	player.setHunger(player.getHunger() - 20);
	player.setEnergy(player.getEnergy() - 20);
	player.gameTime = classTime + 180;
}

void Classroom::printClassMessage(Player player, int _className) const
{
	Tool::clearScreen();
	printInterface(player);
	Tool::setCursorPos(77, 8);
	cout << "本次课程内容是: " << player.getStatus_learning().getSubjectArray()[_className].name;
	Tool::setCursorPos(77, 10);
	cout << "正在学习中...";
	Sleep(3000);
	Tool::setCursorPos(77, 10);
	cout << "叮叮叮,下课了,将自动离开教室";
	Sleep(2000);//防止连击与闪屏
}

void Classroom::olympic(Player& player)
{
	Tool::clearScreen();
	printInterface(player);
	if (player.gameTime / 5760 == 1)
		player.getStatus_learning().getSubjectArray()[6].score += 10;
	else if (player.gameTime / 5760 == 2)
		player.getStatus_learning().getSubjectArray()[12].score += 10;
	Tool::setCursorPos(77, 8);
	cout << "欢迎您参加全国大学生程序设计竞赛! ";
	Tool::setCursorPos(77, 10);
	cout << "正在比赛中...";
	Sleep(3000);
	Tool::setCursorPos(77, 10);
	cout << "叮叮叮,比赛结束,将自动离开考场";
	player.setHunger(player.getHunger() - 20);
	player.setEnergy(player.getEnergy() - 20);
	player.setEmotion(player.getEmotion() - 5);
	player.gameTime += 180;
	Sleep(2000);//防止连击与闪屏
}

void Classroom::examination(Player& player)
{
	Tool::clearScreen();
	printInterface(player);
	Tool::setCursorPos(77, 8);
	cout << "欢迎参加本学年度期末考试！";
	Tool::setCursorPos(77, 10);
	cout << "正在考试中...";
	switch (player.gameTime / 5760)
	{
	case GRADE_1:
	{
		//大一会举行六次考试
		for (int i = 0; i < 6; i++)
		{
			switch (rand() % 2) //先按照考场随机概率加分
			{
			case 0:
				player.getStatus_learning().getSubjectArray()[i].score += 15; //顺利
				break;
			case 1:
				player.getStatus_learning().getSubjectArray()[i].score += 10; //卡壳
				break;
			default:
				player.getStatus_learning().getSubjectArray()[i].score += 5; //备用情况
				break;
			}
			//再把该科目的总分转化为GPA
			player.getStatus_learning().getSubjectArray()[i].conversion(player.getStatus_learning().getSubjectArray()[i].score);
		}
		break;
	}
	case GRADE_2:
	{
		//大二会举行四次考试
		for (int i = 6; i < 10; i++)
		{
			switch (rand() % 2)
			{
			case 0:
				player.getStatus_learning().getSubjectArray()[i].score += 15; //顺利
				break;
			case 1:
				player.getStatus_learning().getSubjectArray()[i].score += 10; //卡壳
				break;
			default:
				player.getStatus_learning().getSubjectArray()[i].score += 5; //备用情况
				break;
			}
			//再把该科目的总分转化为GPA
			player.getStatus_learning().getSubjectArray()[i].conversion(player.getStatus_learning().getSubjectArray()[i].score);
		}
		break;
	}
	case GRADE_3:
	{
		//大三会举行三次考试
		for (int i = 10; i < 13; i++)
		{
			switch (rand() % 2)
			{
			case 0:
				player.getStatus_learning().getSubjectArray()[i].score += 15; //顺利
				break;
			case 1:
				player.getStatus_learning().getSubjectArray()[i].score += 10; //卡壳
				break;
			default:
				player.getStatus_learning().getSubjectArray()[i].score += 5; //备用情况
				break;
			}
			//再把该科目的总分转化为GPA
			player.getStatus_learning().getSubjectArray()[i].conversion(player.getStatus_learning().getSubjectArray()[i].score);
		}
		break;
	}
	default:
		break;
	}
	Sleep(3000);
	Tool::setCursorPos(77, 10);
	cout << "叮叮叮, 考试结束, 将自动离开教室";
	player.gameTime += 300;
	player.setHunger(player.getHunger() - 20);
	player.setEnergy(player.getEnergy() - 20);
	player.setEmotion(player.getEmotion() - 10);
	Sleep(2000);//防止连击与闪屏
}

void Classroom::selfStudy(Player& player)
{

}
