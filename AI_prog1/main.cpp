#include <iostream>
#include <string>
#include <fstream>
#include "Map.h"
using namespace std;

int main ( )
{
	string fileName, line;
	ifstream myFile;
	Map map;

	cout << "Please Enter a LOCATIONS file name" << endl;
	getline(cin, fileName);
	cout << "You entered: " << fileName << endl;
	map.setLocations(fileName);

	cout << "Please Enter a CONNECTIONS file name" << endl;
	getline(cin, fileName);
	cout << "You entered: " << fileName << endl;
	map.setConnections(fileName);

	map.mapCities();

	map.printMap();

	//myFile.open(fileName);

	//if(!myFile) //verify file could be opened
	//{ 
	//	cerr << "Error: file could not be opened" << endl;
	//	exit(1);
	//}
	//else
	//{
	//	/*if (myFile.is_open())
	//		cout << "Opened file: " << myFile << endl;
	//	*/
	//	while (!myFile.eof())
	//	{
	//		getline (myFile, line);
	//		cout << line << endl;
	//	}
	//	myFile.close();
	//}
	
	getchar();
	return 0;
}