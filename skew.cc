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
	
	float sx = atof(argv[2]);
	float sy = atof(argv[3]);
	string name = argv[1];
	
	skew(name, sx, sy);
	
	return 0;
}

void useage()
{
	cout << endl;
	cout << "Usage: " << endl;
	cout << "skew name xs xy\n";;
	cout << "name is the name of the file to be written to\n";
	cout << "xs and xy are the skew factors in the x and y directions\n";
}