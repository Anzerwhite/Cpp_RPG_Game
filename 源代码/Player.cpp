#include "Player.h"
using namespace std;

Player::Player()
{
	gameTime = 0;//初始时间
}

string Player::getGenderName() const
{
	switch (gender)
	{
	case GIRL:
		return string("女");
		break;
	case BOY:
		return string("男");
		break;
	default:
		break;
	}
	return string();
}

string Player::getGradeName() const
{
	switch (getGrade())
	{
	case GRADE_1:
		return string("大一");
		break;
	case GRADE_2:
		return string("大二");
		break;
	case GRADE_3:
		return string("大三");
		break;
	case GRADE_4:
		return string("大四");
		break;
	default:
		break;
	}

}

string Player::getStatus_familyName() const
{
	switch (Status_family)
	{
	case RICH:
		return string("富裕");
		break;
	case NORMAL:
		return string("小康");
		break;
	case POOR:
		return string("贫困");
		break;
	default:
		break;
	}
}

void Player::printPlayer() const
{

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, getPosition());
	Tool::setColor(SKYBLUE, BLACK);
	cout << "坤";
	Tool::setDefaultColor();
}

pair<int, unsigned long> Player::getClass() const
{
	int classNum = 0;
	unsigned long times = 0;
	switch (gameTime / 5760)
	{
	case 0:
		switch (gameTime / 1440 % 4)
		{
		case 0://大一秋
			if (gameTime / 60 % 24 <= 10)
			{
				classNum = 0;
				times = 540;
			}
			else if (gameTime / 60 % 24 <= 15 && gameTime / 60 % 24 >= 13)
			{
				classNum = 1;
				times = 840;
			}
			break;
		case 1://大一冬
			if (gameTime / 60 % 24 <= 10)
			{
				classNum = 2;
				times = 540 + 1440;
			}
			else if (gameTime / 60 % 24 <= 15 && gameTime / 60 % 24 >= 13)
			{
				classNum = 3;
				times = 840 + 1440;
			}
			break;
		case 2://大一春
			if (gameTime / 60 % 24 <= 10)
			{
				classNum = 4;
				times = 540 + 1440 + 1440;
			}
			else if (gameTime / 60 % 24 <= 20 && gameTime / 60 % 24 >= 18)
			{
				classNum = 5;
				times = 1140 + 1440 + 1440;
			}
			break;
		case 3://大一夏
			break;
		}
		break;
	case 1:
		switch (gameTime / 1440 % 4)
		{
		case 0://大二秋
			if (gameTime / 60 % 24 <= 10)
			{
				classNum = 6;
				times = 540 + 1440 + 1440 + 1440 + 1440;
			}
			else if (gameTime / 60 % 24 <= 15 && gameTime / 60 % 24 >= 13)
			{
				classNum = 7;
				times = 840 + 1440 + 1440 + 1440 + 1440;
			}
			break;
		case 1://大二冬
			if (gameTime / 60 % 24 <= 20 && gameTime / 60 % 24 >= 18)
			{
				classNum = 8;
				times = 1140 + 1440 + 1440 + 1440 + 1440 + 1440;
			}
			break;
		case 2://大二春
			if (gameTime / 60 % 24 <= 10)
			{
				classNum = 9;
				times = 540 + 1440 + 1440 + 1440 + 1440 + 1440 + 1440;
			}
			break;
		case 3://大二夏
			break;
		}
		break;
	case 2:
		switch (gameTime / 1440 % 4)
		{
		case 0://大三秋
			if (gameTime / 60 % 24 <= 10)
			{
				classNum = 10;
				times = 540 + 1440 * 8;
			}
			break;
		case 1://大三冬
			if (gameTime / 60 % 24 <= 15 && gameTime / 60 % 24 >= 13)
			{
				classNum = 11;
				times = 840 + 1440* 9;
			}
			break;
		case 2://大三春
			if (gameTime / 60 % 24 <= 10)
			{
				classNum = 12;
				times = 540  + 1440 * 10;
			}
			break;
		case 3://大三夏
			break;
		}
		break;
	}
	return pair<int, unsigned long>(classNum, times);
}

