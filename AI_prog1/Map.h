#pragma once
#include <string>
#include <vector>
#include <list>
using namespace std;

#include "City.h"

class Map
{
private:
	vector<string> connections;
	vector<string> locations;
	vector<City> cities;
	list<City> path;
	
public: 
	Map();
	~Map();

	//Retrieve the locations file
	//takes the path to where the file is located
	//returns 0 if file is found
	//returns -1 if file is not found
	int setLocations( string );

	//Retrieves the connections file
	//takes the path to the file as an argument
	//returns 0 if file is found
	// return -1 if file is not found
	int setConnections( string );

	//Creates the map of the cities
	void mapCities();

	//Finds the shortest path from one city to another
	//takes as arguments:
	//starting city, ending city, city to omit
	int findPath(string, string, string);
	
	//Display the shortest path from one city to another
	//if one is found
	void showPath();	

	void printMap();
};