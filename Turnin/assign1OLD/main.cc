#include "functions.h"
#include <iostream>
using namespace std;

//outputs a menu for you
int menu();

//main function, runs the menu ONCE!
int main()
{
	//get user choice
	int choice = 0;	
	choice = menu();
	
	//Run the corresponding algorithm based on choice
	//after getting the parameters required for that algorithm
	if(choice == 1)
	{
		float xs, xy;
		cout << "Please enter the scaling factor for x: ";
		cin >> xs;
		cout << "Please enter the scaling factor for y: ";
		cin >> xy;
		
		skew(xs, xy);
	}
	else if(choice == 2)
	{
		float angle;
		cout << "Please enter the twisting angle factor in degrees: ";
		cin >> angle;
		
		twist(angle);
	}
	else if(choice == 3)
	{
		float xFact;
		cout << "Please enter the distance to extrude by: ";
		cin >> xFact;
		
		extrude(xFact);
	}
	else if(choice == 4)
	{
		int sFact;
		float angle;
		
		cout << "Please enter the amount of steps to sweep by: ";
		cin >> sFact;
		cout << "Please enter the angle to sweep in degrees: ";
		cin >> angle;
		
		sweep(sFact, angle);
	}
	
	//let you know we've finished
	cout << endl << "Done!" << endl;
	
	return 0;
}

//outputs a menu and gets the users choice
int menu()
{
	//output the menu
	cout << "CSCI 490 Transformations Menu" << endl;
	cout << "=============================" << endl;
	cout << "1. Skew" << endl;
	cout << "2. Twist" << endl;
	cout << "3. Extrude" << endl;
	cout << "4. Sweep" << endl;
	cout << "5. Exit" << endl;
	
	//get user choice
	cout << "Choice: ";
	int choice;
	cin >> choice;
	
	//return it
	return choice;
}

