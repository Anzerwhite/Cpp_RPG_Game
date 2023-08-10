#ifndef MAP_H
#define MAP_H
#include"Place.h"
#include<vector>
using std::vector;

//生活区
//extern Place dorm; // 宿舍
//extern Place gym; // 运动馆
//extern Place diningHall; // 饭堂
//extern Place supermarket; // 超市
//extern Place hospital; // 医院
//
//extern Place bridge; //桥梁
//
////教学区
//extern Place classroom; // 课室(上课，随机点名（随机数）)
//extern Place library; // 图书馆（自习，效率一致）
//extern Place lab; // 实验室（增加项目经历）门槛：至少大二，加权平均数大于等于2



class Map
{
public:
	Map();
	virtual ~Map();
	virtual void printMap() const = 0;
	const vector<Place*>& getPlaceArray() const { return placeArray; }
protected:
	vector<Place*> placeArray;//存放具体地点的数组
};




#endif // !MAP_H

