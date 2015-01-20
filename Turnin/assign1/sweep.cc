#include "functions.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void useage();

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		useage();
		return -1;
	}
	
	int sFact = atoi(argv[2]);
	float angle = atof(argv[3]);
	string name = argv[1];
	
	sweep(name, sFact, angle);
}

void useage()
{
	cout << endl;
	cout << "Usage: " << endl;
	cout << "skew name sFact angle\n";;
	cout << "name is the name of the file to be written to\n";
	cout << "sFact is the amount of steps to sweep in\n";
	cout << "angle is the total angle to sweep in degrees\n";
}