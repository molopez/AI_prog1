#pragma once
#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

class City
{
public:
	//Constructors
	City(string, int, int);
	~City(void);

	//Methods
	void addNeighbor(string, int, int);
	void setVisit(bool);
	void setOmission(bool);
	void setEnd(bool deadEnd);
	void setDistanceTraveled(int);
	void setPreviousCity(string);
	bool getVisit(void);
	bool getOmmission(void);
	bool getEnd(void);
	string getPreviousCity(void);
	int getDistanceTraveled(void);
	void toString(void);
	string getCityName(void);
	void printNeighbors(void);
	int getXCoordinate(void);
	int getYCoordinate(void);
	

private:
	//Properties
	string cityName, previousCity;
	int xCoordinate, yCoordinate, distanceTraveled;
	bool visited, omitted, deadEnd;
	map<string,int> Neighbor;

	//Methods
	int calculateDistance(int,int);
};
