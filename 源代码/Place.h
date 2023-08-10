#pragma once
#include<iostream>
#include<vector>
#include<Windows.h>
#include"Player.h"
#include"Article.h"
#include"ArticleStore.h"
#define WIDTH 160
#define HIGH 40
using std::vector;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //用来检测按键的点击事件

class Place
{
public:
	Place(short x, short y);//构造函数
	virtual ~Place();
	
	void setPosition(short x, short y) { position.X = x; position.Y = y; }//
	COORD getPostion() const { return position; }
	virtual void printInterface(Player player) const;//打印界面
	void printArticle() const;//打印物品
	void normalFunction(Player& player);
	virtual void printPlace() const = 0;//打印地点图标
	virtual void placeFunction(Player& player) = 0; //具体地点的功能函数
protected:
	COORD position;//坐标
	vector<Article*> articleArray;//存放菜单
};




