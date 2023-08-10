#pragma once
#include"Map.h"
#include"Bridge.h"
#include"Classroom.h"
#include"Lab.h"
#include"Library.h"
class TeachingArea : public Map
{
public:
	TeachingArea();
	virtual ~TeachingArea();
	virtual void printMap() const;//打印地图
};

