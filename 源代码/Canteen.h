#pragma once
#include "Place.h"
using std::vector;
class Canteen :public Place
{
public:
	Canteen(short x, short y);
	virtual ~Canteen();
	virtual void printInterface(Player player) const override;
	virtual void printPlace() const ;//打印地点图标
	virtual void placeFunction(Player& player);//功能函数
};

