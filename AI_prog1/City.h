#pragma once
#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

class City
{
public:
	//Properties
	string cityName;
	int xCoordinate, yCoordinate;
	bool visited, omitted, deadEnd;
	map<string,int> Neighbor;

	//Constructors
	City(string, int, int);
	~City(void);

	//Methods
	void addNeighbor(string, int, int);
	void setVisit(bool visited);
	void setOmission(bool omitted);
	void setEnd(bool deadEnd);
	bool getVisit(void);
	bool getOmmission(void);
	bool getEnd(void);
	void toString();

private:
	//Methods
	int calculateDistance(int,int);
};
