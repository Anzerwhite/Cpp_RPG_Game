#ifndef TOOL_H
#define TOOL_H
#include<Windows.h>
//工具类，存放一些控制的工具函数
enum BagOption {
	NOPACKAGE = 0, PACKAGE_1 = 1, PACKAGE_2, PACKAGE_3, PACKAGE_4, PACKAGE_5, PACKAGE_6, PACKAGE_7, PACKAGE_8, PACKAGE_9, PACKAGE_10,
	PACKAGE_11, PACKAGE_12, PACKAGE_13, PACKAGE_14, PACKAGE_15, PACKAGE_16, PACKAGE_17, PACKAGE_18, PACKAGE_19, PACKAGE_20, CHECK, ESCBAG
};
enum  Color
{
	BLACK = 0, DARKBLUE, DARKGREEN, LIGHTBLUE, DARKRED, PURPLE,
	DARKYELLOW, LIGHTGREY, DARKGREY, SKYBLUE, LIGHTGREEN, MINT,
	LIGHTRED, ROSERED, LIGHTYELLOW, WHITE
};


//struct 
class Tool
{
public:
	static void clearScreen();//清屏
	static void hideCursor();//隐藏光标
	static void setCursorPos(int x, int y);//设置光标位置
	static void setColor(Color fore, Color back);//设置颜色
	static void setDefaultColor();
	static BagOption GetBagOptionPos(int x, int y);
	static void setBagOptionHighLight(BagOption bagOption);//点击高亮
	static void setBagOptionDefault(BagOption bagOption);//恢复默认
private:
	

};
#endif // !TOOL_H