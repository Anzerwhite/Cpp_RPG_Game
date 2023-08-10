#include "Tool.h"

void Tool::clearScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//创建一个输出端的句柄
	COORD coordScreen = { 0, 0 };//清屏后光标初始位置
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;


	// 获取当前缓冲区的字符单元数
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;//控制台大小
	//setColor(LIGHTBLUE, WHITE);
	//用空格填补整个屏幕
	if (!FillConsoleOutputCharacterW(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten))
	{
		return;
	}

	//获取当前文本属性
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	//对应的设置缓冲区的属性

	if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten))
	{
		return;
	}
	//setColor(WHITE, BLACK);
	SetConsoleCursorPosition(hConsole, coordScreen);

}

void Tool::hideCursor()
{
	// 获取标准输出的句柄
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// 获取当前光标信息
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hOut, &cursorInfo);
	// 修改光标信息
	cursorInfo.bVisible = !cursorInfo.bVisible; // 隐藏光标
	// 设置新的光标信息
	SetConsoleCursorInfo(hOut, &cursorInfo);
}

void Tool::setCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Tool::setColor(Color fore, Color back)//
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (back << 4) + fore);//位运算，高四位表示背景色，第四位表示前景色
}

void Tool::setDefaultColor()
{
	setColor(WHITE, BLACK);
}

BagOption Tool::GetBagOptionPos(int x, int y)
{
	if (x >= 0 && x <= 33)//左侧
		switch (y)
		{
		case 10:
			return BagOption(PACKAGE_1);
			break;
		case 11:
			return BagOption(PACKAGE_2);
			break;
		case 12:
			return BagOption(PACKAGE_3);
			break;
		case 13:
			return BagOption(PACKAGE_4);
			break;
		case 14:
			return BagOption(PACKAGE_5);
			break;
		case 15:
			return BagOption(PACKAGE_6);
			break;
		case 16:
			return BagOption(PACKAGE_7);
			break;
		case 17:
			return BagOption(PACKAGE_8);
			break;
		case 18:
			return BagOption(PACKAGE_9);
			break;
		case 19:
			return BagOption(PACKAGE_10);
			break;
		}
	else if (x >= 33 && x <= 65)//右侧
		switch (y)
		{
		case 10:
			return BagOption(PACKAGE_11);
			break;
		case 11:
			return BagOption(PACKAGE_12);
			break;
		case 12:
			return BagOption(PACKAGE_13);
			break;
		case 13:
			return BagOption(PACKAGE_14);
			break;
		case 14:
			return BagOption(PACKAGE_15);
			break;
		case 15:
			return BagOption(PACKAGE_16);
			break;
		case 16:
			return BagOption(PACKAGE_17);
			break;
		case 17:
			return BagOption(PACKAGE_18);
			break;
		case 18:
			return BagOption(PACKAGE_19);
			break;
		case 19:
			return BagOption(PACKAGE_20);
			break;
		}
	else if (x >= 95 && x <= 98 && y == 19)
		return ESCBAG;
	else if (x >= 95 && x <= 98 && y == 17)
		return CHECK;
	else
		return NOPACKAGE;
}

void Tool::setBagOptionHighLight(BagOption bagOption)
{
	COORD _position = { 0, 0 };
	DWORD dwWriteCoord;
	switch (bagOption)
	{
	case NOPACKAGE:
		break;
	case PACKAGE_1:
		_position = { 1, 10 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_2:
		_position = { 1, 11 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_3:
		_position = { 1, 12 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_4:
		_position = { 1, 13 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_5:
		_position = { 1, 14 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_6:
		_position = { 1, 15 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_7:
		_position = { 1, 16 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_8:
		_position = { 1, 17 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_9:
		_position = { 1, 18 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_10:
		_position = { 1, 19 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_11:
		_position = { 34, 10 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_12:
		_position = { 34, 11 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_13:
		_position = { 34, 12 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_14:
		_position = { 34, 13 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_15:
		_position = { 34, 14 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_16:
		_position = { 34, 15 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_17:
		_position = { 34, 16 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_18:
		_position = { 34, 17 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_19:
		_position = { 34, 18 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_20:
		_position = { 34, 19 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 31, _position, &dwWriteCoord);
		break;
	case ESCBAG:
		_position = { 95, 19 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (LIGHTGREY << 4) + WHITE, 4, _position, &dwWriteCoord);
		break;
	default:
		break;
	}
}

void Tool::setBagOptionDefault(BagOption bagOption)
{
	COORD _position = { 0, 0 };
	DWORD dwWriteCoord;
	switch (bagOption)
	{
	case NOPACKAGE:
		return;
		break;
	case PACKAGE_1:
		_position = { 1, 10 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_2:
		_position = { 1, 11 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_3:
		_position = { 1, 12 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_4:
		_position = { 1, 13 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_5:
		_position = { 1, 14 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_6:
		_position = { 1, 15 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_7:
		_position = { 1, 16 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_8:
		_position = { 1, 17 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_9:
		_position = { 1, 18 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_10:
		_position = { 1, 19 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_11:
		_position = { 34, 10 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_12:
		_position = { 34, 11 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_13:
		_position = { 34, 12 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_14:
		_position = { 34, 13 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_15:
		_position = { 34, 14 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_16:
		_position = { 34, 15 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_17:
		_position = { 34, 16 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_18:
		_position = { 34, 17 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_19:
		_position = { 34, 18 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	case PACKAGE_20:
		_position = { 34, 19 };
		FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK | WHITE, 31, _position, &dwWriteCoord);
		break;
	default:
		break;
	}
}
