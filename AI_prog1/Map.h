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
	map<City, int> heuristics;
	bool pathFound;
	
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

private:
	int heuristicDistance(City, City);

	//pass in the name of the city
	//and returns its neighbors
	map<string, int> getNeighborCities(string);

	//for each adjacent(neighbor) city
	//pass the city name and distance from current city
	//Method will calculate the SLD + DT and add the 
	//city and the heuristic distance to the 
	//heuristics map structure
	void setupHeuristic(string, int);

	//finds the next city that would give us the
	//next shortest distance to travel through
	string getNextCity();
};