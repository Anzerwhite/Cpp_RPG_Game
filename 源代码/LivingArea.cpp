#include "LivingArea.h"
using namespace std;
LivingArea::LivingArea()
{
	//初始化各具体地点
	Place* bridge = new Bridge(0, 19);
	placeArray.push_back(bridge);

	Place* dorm = new Dorm(80, 19);
	placeArray.push_back(dorm);

	Place* gym = new Gym(40, 30);
	placeArray.push_back(gym);

	Place* canteen = new Canteen(120, 30);
	placeArray.push_back(canteen);

	Place* supermarket = new Supermarket(40, 10);
	placeArray.push_back(supermarket);

	Place* hospital = new Hospital(120, 10);
	placeArray.push_back(hospital);
	
	
}

LivingArea::~LivingArea()
{
	for (Place*& element : placeArray)
	{
		delete element;
	}
}

void LivingArea::printMap() const
{
	for (Place* element : placeArray)
		element->printPlace();
}
