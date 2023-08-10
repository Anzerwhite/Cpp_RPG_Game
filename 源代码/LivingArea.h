#pragma once
#include "Map.h"
#include"Dorm.h"
#include"Gym.h"
#include"Hospital.h"
#include"Canteen.h"
#include"Bridge.h"
#include"Supermarket.h"
class LivingArea :public Map
{
public:
	LivingArea();
	virtual ~LivingArea();
	virtual void printMap() const;//打印地图
};

