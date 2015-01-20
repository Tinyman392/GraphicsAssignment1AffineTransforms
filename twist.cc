#include "functions.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void useage();

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		useage();
		return 0;
	}
	
	float angle = atof(argv[2]);
	string name = argv[1];
	
	twist(name, angle);
	
	return 0;
}

void useage()
{
	cout << endl;
	cout << "Usage: " << endl;
	cout << "twist name angle\n";;
	cout << "name is the name of the file to be written to\n";
	cout << "angle is the twist factor used by the program to twist\n";
}