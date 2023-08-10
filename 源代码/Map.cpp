#include "Map.h"

Map::Map()
{

}

Map::~Map()
{
}

void Map::printMap() const
{
	for (const Place* element : placeArray)
	{
		element->printPlace();
	}
}


