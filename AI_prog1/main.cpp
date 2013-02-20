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

	//cout << "Please Enter a LOCATIONS file name" << endl;
	//getline(cin, fileName);

	fileName = "C:\\Users\\VA - Ivory\\Documents\\Visual Studio 2012\\USF\\AI\\AI_prog1\\txt_files\\locsamp.txt";
	cout << "You entered: " << fileName << endl;
	map.setLocations(fileName);

	//cout << "Please Enter a CONNECTIONS file name" << endl;
	//getline(cin, fileName);

	fileName = "C:\\Users\\VA - Ivory\\Documents\\Visual Studio 2012\\USF\\AI\\AI_prog1\\txt_files\\connsamp.txt";
	cout << "You entered: " << fileName << endl;
	map.setConnections(fileName);

	map.mapCities();

	//map.printMap();

	string start = "D5", finish = "A1", omit = "B5";
	
	//cout << "Enter starting city: " ;
	//cin >> start;
	cout << "start: " << start << endl;

	//cout << "Enter ending city: ";
	//cin >> finish;
	cout << "end: " << finish << endl;


	//cout << "Enter city to omit: ";
	cin >> omit;
	cout << "omit: " << omit << endl;

	//cout << start << " " << finish << " " << omit << endl;


	map.findPath(start, finish, omit);

	cout << "you entered: " << start << " " << finish << " " << omit << endl;

	map.showPath();

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