#include "City.h"

City::City(string cityName, int x, int y)
{
	this->cityName = cityName;
	xCoordinate = x;
	yCoordinate = y;
	visited = false;
	omitted = false;
	deadEnd = false;
}

City::~City(void)
{
}

void City::addNeighbor(string cityName, int x, int y)
{
	Neighbor.insert(pair<string, int>(cityName, calculateDistance(x,y)));
}

void City::setVisit(bool visited)
{
	this->visited = visited;
}

void City::setOmission(bool omitted)
{
	this->omitted = omitted;
}

void City::setEnd(bool deadEnd)
{
	this->deadEnd = deadEnd;
}

bool  City::getVisit(void)
{
	return visited;
}

bool  City::getOmmission(void)
{
	return omitted;
}

bool  City::getEnd(void)
{
	return deadEnd;
}

int  City::calculateDistance(int x, int y)
{
	return sqrt(pow(xCoordinate - x,2) + pow(yCoordinate - y,2));
}

