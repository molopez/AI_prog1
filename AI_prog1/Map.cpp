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
	string cityName, temp, neighbor, neighborCity, tempNeighbor;
	int locX, locY, numNeighbors, tempLoc; 
	vector<string>::iterator itLoc, itConn;
	vector<City>::iterator itCity;
	stringstream ssLoc, ssConn, ssTemp;

	//cout << "locations Building:" << endl;
	//Building vector of cities
	//initializing the cities using the conections file first
	for (itLoc = locations.begin() ; itLoc != locations.end(); ++itLoc)
	{
		temp = *itLoc;
		//cout << temp << " " ;
		
		if(temp.compare("END") == 0)
			break;
		
		ssLoc << (*itLoc);
		ssLoc >> cityName;
		ssLoc >> locX;
		ssLoc >> locY;
		ssLoc.clear();

		City city(cityName, locX, locY);
		cities.push_back(city);
		
		//cout << cityName << " " << locX << " " << locY << endl;
	}

	/*cout << "verify vector of cities created properly:" << endl;
	for (itCity = cities.begin() ; itCity != cities.end(); ++itCity)
	{
		(*itCity).toString();
	}*/

	//add adjacent cities to each city
	//iterate through the connections list to add each adjacent(neighbor) city
	for(itConn = connections.begin(); itConn != connections.end(); ++itConn)
	{
		temp = *itConn;
		//cout << temp << " " ;
		
		if(temp.compare("END") == 0)
			break;

		ssConn << (*itConn);
		ssConn >> cityName;
		ssConn >> numNeighbors;

		//find the city to add its neighbors
		for (itCity = cities.begin() ; itCity != cities.end(); ++itCity)
		{

			temp = (*itCity).getCityName();

			//if this is the city i am on, add its neighbors
			if(temp.compare(cityName) == 0) 
			{

				//add the neighbors the city has
				for (int i = 0; i < numNeighbors; ++i)
				{
					ssConn >> neighbor;
				
					//find the location of the neighbor
					for (itLoc = locations.begin() ; itLoc != locations.end(); ++itLoc)
					{
						temp = *itLoc;
						ssTemp << (*itLoc);
						ssTemp >> tempNeighbor;
						ssTemp >> tempLoc; //no function, only used to clear the streambuffer
						ssTemp >> tempLoc; //no function, only used to clear the streambuffer
						ssTemp.clear();
						//cout << temp << " " ;
		
						//if this is the neighbor, add it to the city
						if(tempNeighbor.compare(neighbor) == 0)
						{			
							ssLoc << (*itLoc);
							ssLoc >> neighborCity;
							ssLoc >> locX;
							ssLoc >> locY;
							ssLoc.clear();

							(*itCity).addNeighbor(neighborCity, locX, locY); 
						}
					}
				}
			}
		}

		ssConn.clear(); //clear stream to capture next input string
	}	
}

void Map::printMap()
{
	cout << "verify neighbors of cities created properly:" << endl;
	for (vector<City>::iterator itCity = cities.begin() ; itCity != cities.end(); ++itCity)
	{
		(*itCity).printNeighbors();
		cout << endl;
	}
}

int Map::findPath(string start, string finish, string omit)
{
	return 0;
}

void Map::showPath()
{

}

