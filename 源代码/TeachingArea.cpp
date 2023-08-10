#include "TeachingArea.h"

TeachingArea::TeachingArea()
{
	Place* bridge = new Bridge(158, 19);
	placeArray.push_back(bridge);
	Place* classroom = new Classroom(100, 30);
	placeArray.push_back(classroom);
	Place* library = new Library(100, 10);
	placeArray.push_back(library);
	Place* lab = new Lab(40, 19);
	placeArray.push_back(lab);
}

TeachingArea::~TeachingArea()
{
	for (Place*& element : placeArray)
	{
		delete element;
	}
}

void TeachingArea::printMap() const
{
	for (Place* element : placeArray)
	{
		element->printPlace();
	}
}
