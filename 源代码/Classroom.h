#pragma once
#include "Place.h"
class Classroom :public Place
{
public:
	Classroom(short x, short y);
	virtual void printInterface(Player player) const override;
	virtual void printPlace() const ;//打印地点图标
	virtual void placeFunction(Player& player); //功能函数

	void havingClass(Player& player);
	void printClassMessage(Player player, int _className) const;
	void olympic(Player& player);
	void examination(Player& player);
	void selfStudy(Player& player);
};

