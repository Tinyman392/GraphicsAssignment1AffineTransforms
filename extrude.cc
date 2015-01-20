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
		return -1;
	}
	
	float xFact = atof(argv[2]);
	string name = argv[1];
	
	extrude(name, xFact);
}

void useage()
{
	cout << endl;
	cout << "Usage: " << endl;
	cout << "skew name xFact\n";;
	cout << "name is the name of the file to be written to\n";
	cout << "xFact is the amount to extrude by\n";
}