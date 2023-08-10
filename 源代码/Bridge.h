#pragma once
#include "Place.h"

class Bridge : public Place
{
public:
	Bridge(short x, short y);
	virtual void printPlace() const ;//打印地点图标
	virtual void placeFunction(Player& player);//功能函数
};

