#pragma once
#include "Place.h"
class Supermarket :public Place
{
public:
	Supermarket(short x, short y);
	virtual void printInterface(Player player) const override;
	virtual void printPlace() const ;//打印地点图标
	virtual void placeFunction(Player& player); //功能函数
};

