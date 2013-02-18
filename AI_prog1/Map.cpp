#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

#include "Map.h" 
 
Map::Map(){}

Map::~Map(void){}

int Map::setLocations(string fileName)
{
	string line;
	ifstream file;

	file.open(fileName);

	if(!file) //verify file could be opened
	{ 
		cerr << "Error: file could not be opened" << endl;
		return -1;
	}
	else
	{
		while (!file.eof())
		{
			getline (file, line);
			locations.push_back(line);
			//cout << line << endl;			
		}
		file.close();
		
		/*cout << "locations contains:" << endl;
		for (vector<string>::iterator it = locations.begin() ; it != locations.end(); ++it)
		{
			cout << ' ' << *it;
			cout << '\n';
		}*/
	}

	return 0;
}

int Map::setConnections(string fileName)
{
	string line;
	ifstream file;

	file.open(fileName);

	if(!file) //verify file could be opened
	{ 
		cerr << "Error: file could not be opened" << endl;
		return -1;
	}
	else
	{
		while (!file.eof())
		{
			getline (file, line);
			connections.push_back(line);
			//cout << line << endl;
		}
		file.close();

		/*cout << "connections contains:" << endl;
		for (vector<string>::iterator it = connections.begin() ; it != connections.end(); ++it)
			{
				cout << ' ' << *it;
				cout << '\n';
			}*/
	}

	return 0;
}

void Map::mapCities()
{
	string cityName, temp;
	int locX, locY; 

	cout << "locations Building:" << endl;
	for (vector<string>::iterator it = locations.begin() ; it != locations.end(); it++)
	{
		temp = *it;
		//cout << temp << " " ;
		
		if(temp.compare("END") == 0)
			break;
		
		stringstream ss(*it);
		ss >> cityName;
		ss >> locX;
		ss >> locY;

		City city(cityName, locX, locY);
		cities.push_back(city);
		
		cout << cityName << " " << locX << " " << locY << endl;
	}

	/*cout << "connections contains:" << endl;
		for (vector<string>::iterator it = connections.begin() ; it != connections.end(); ++it)
			{
				cout << ' ' << *it;
				cout << '\n';
			}*/
}

int Map::findPath(string start, string finish, string omit)
{
	return 0;
}

void Map::showPath()
{

}

