#include "polyread.h"
#include <fstream>
#include <iostream>
#include "functions.h"

const int COORD_SIZE = 1000000;
const int VERT_LIST_SIZE = 1000000;
const float PI = 3.141592654;
const float RADFACTOR = PI / 180;

//Asks user for a file name, returns the input
string getFileName()
{
	//return string
	string name = "";
	//ask user for file name containing polyset
	cout << "Please enter file containing PolySet: ";
	//gets file name input
	cin >> name;
	
	//returns it
	return name;
}

//takes a polyset an skews it
int skew(string &name, float sx, float sy)
{
	//parameters for parsing polyset
	string vType = "      ";
	int nVert = 0;
	int nFace = 0;
	float coord[COORD_SIZE];
	int vertList[VERT_LIST_SIZE];
	int err = 0;
	
	//parse polyset and fill params
	err = parsePolySet(name, vType, nVert, nFace, coord, vertList);
	
	//Append SKEW to the end of the file name
	name += "SKEW";
	
	//if we had an error parsing, we return it
	if(err == -1)
		return err;
	
	//get the size of the vertex
	int vSize = get_vertex_size(vType);
	
	//We will go through the vertex values and skew the x and y coordinates
	for(int i = 0; i < nVert; i++)
	{
		//set c to the proper area in the coord list
		//it would be i (vertex we are dealing with
		//multipled by the size of the vertex
		int c = i*vSize;
		
		//set the coordinate to skew factor * z-coord + itself
		coord[c] += sx*coord[c+2];
		coord[c+1] += sy*coord[c+2];
		
		//because the z coordinate doesn't change, we won't edit the 
		//z coordinate (coord[c+2]) since we aren't adding any new vertices
	}
	
	//output the information
	outNewPolySet(name, vType, nVert, nFace, coord, vertList);
	
	//err will be 0 if everything went swimmingly
	return err;
}

//takes a polyset and twists it
int twist(string & name, float angle)
{
	//parameters for parse function
	string vType = "";
	int nVert = 0;
	int nFace = 0;
	float coord[COORD_SIZE];
	int vertList[VERT_LIST_SIZE];
	int err = 0;
	
	//convert the angle to radians
	angle *= RADFACTOR;
	
	//parse polyset and fill those params
	err = parsePolySet(name, vType, nVert, nFace, coord, vertList);
	
	//add TWIST to the end of the name
	name += "TWIST";
	
	//if error, we return error
	if(err == -1)
		return err;
	
	//get the size of the vertex
	int vSize = get_vertex_size(vType);
	
	int c = 0;
	
	//go through and twist the x and y coordinates appropriately
	for(int i = 0; i < nVert; i++)
	{
		//Again, set the c to the proper location in the list
		c = i*vSize;
		//Angle of twist is based on the height from the z-coordinate
		//We multiply it by the z coordinate.
		float angleF = angle*coord[c+2];
		
		int x = coord[c];
		int y = coord[c+1];
		
		//set the x and y coordinates like below
		coord[c] = x*cos(angleF) - y*sin(angleF);
		coord[c+1] = y*cos(angleF) + x*sin(angleF);
		
		//no need to alter the z since it doesn't change.
	}
	
	//output the polyset
	outNewPolySet(name, vType, nVert, nFace, coord, vertList);
	
	//return 0
	return err;
}

//Performs extrude on a polyset
int extrude(string& name, float xFact)
{
	//parameters for parsing
	string vType = "";
	int nVert = 0;
	int nFace = 0;
	float coord[COORD_SIZE];
	int vertList[VERT_LIST_SIZE];
	int err = 0;
	
	//parse the polyset
	err = parsePolySet(name, vType, nVert, nFace, coord, vertList);
	
	name += "EXTRUDE";
	
	//if parsing provided error, return
	if(err == -1)
		return err;
	
	//get the vertex size
	int vSize = get_vertex_size(vType);
	
	//get the number of edges
	int nEdge = 0;
	
	//generic counter c
	int c = 0;
	//count the edges
	//nEdge = number of items in vertList != -1
	for(int i = 0; i < nFace;)
	{
		//the vertex we are reading is -1
		//we know we've hit a face
		if(vertList[c] == -1)
		{
			i++;
		}
		//if it's not -1. we will increment nEdge
		else
		{
			nEdge++;
		}
		//increment our counter c
		c++;
	}
	
	//check for overflow of points
	c = nVert * vSize;
	if(2*c > COORD_SIZE)
		return -1;
	
	//generic counters
	int c2 = 0;
	int c3 = 0;
	//go through and fill vertices
	for(int i = 0; i < nVert; i++)
	{
		//c3 is used as a counter to count how far into the vertList
		//we've gone since the current iteration
		//it's reset at each iteration
		c3 = 0;
		//set c2 to be the current vertex
		c2 = i*vSize;
		//set c to be the current vertex + number of edges
		c = (c2 / vSize + nEdge) * vSize;
		
		//Don't change the x and y coordinates
		//increment c each time
		coord[c++] = coord[c2++]; c3++;
		coord[c++] = coord[c2++]; c3++;
		//z coordinate is set to xFact, the amount of extrusion
		coord[c++] = xFact; c3++;
		
		//fill in the rest of the vertex information
		for(;c3 < vSize; c3++)
		{
			coord[c++] = coord[c2++];
		}
	}
	//our vertex count has doubled
	nVert = nVert * 2;
	
	//make sure we don't overflow faces
	c = nEdge*5 + 2*(nFace+nEdge);
	if(c > VERT_LIST_SIZE)
		return -1;
	
	//set c accordingly
	c = nEdge + nFace;
	//reset c2 accordingly
	c2 = 0;
	c3 = 0;
	//draw the faces
	for(int i = 0; i < nFace;)
	{
		//if we are at -1, we want to wrap back around
		if(vertList[c2 + 1] == -1)
		{
			vertList[c++] = vertList[c2];
			vertList[c++] = vertList[c2] + nEdge;
			vertList[c++] = vertList[c3] + nEdge;
			vertList[c++] = vertList[c3];
			vertList[c++] = -1;
			
			//increment c2 to the proper place
			c2 += 2;
			//set c3 properly
			c3 = c2;
			//increment i
			i++;
		}
		//if we don't hit a -1, we continue going
		//connecting the vertices n, n+nEdge, m, m+nEdge
		//For -1, c3 = m, c2 = n
		//If not, then c2 = m, c2++ = n
		else
		{
			vertList[c++] = vertList[c2];
			vertList[c++] = vertList[c2] + nEdge;
			c2++;
			vertList[c++] = vertList[c2] + nEdge;
			vertList[c++] = vertList[c2];
			vertList[c++] = -1;
		}
	}
	
	//reset c2 and c3
	c2 = 0;
	c3 = 0;
	
	//draw the end cap
	for(int i = 0; i < nFace;)
	{
		//if we hit a -1
		//we hit the end of a face
		//we also want to add the -1 the list
		if(vertList[c2] == -1)
		{
			i++;
			vertList[c++] = -1;
		}
		//otherwise, we just select the appropriate vertex to cap with
		else
		{
			vertList[c++] = vertList[c2] + nEdge;
		}
		c2++;
	}
	vertList[c++] = -2;
	
	//update the number of faces
	nFace += nEdge + nFace;
	
	//output the new polyset
	outNewPolySet(name, vType, nVert, nFace, coord, vertList);
	
	//return 0
	return err;
}

//sweeps a given polyset
int sweep(string &name, int sFact, float angle)
{
	//params for parsing
	string vType = "";
	int nVert = 0;
	int nFace = 0;
	float coord[COORD_SIZE];
	int vertList[VERT_LIST_SIZE];
	int err = 0;
	
	//fill the params
	err = parsePolySet(name, vType, nVert, nFace, coord, vertList);
	
	name += "SWEEP";
	
	//if there was an error parsing, we return
	if(err == -1)
		return err;
	
	//get the vertex size
	int vSize = get_vertex_size(vType);
	
	//count the number of edges
	int nEdge = 0;
	int c = 0;
	for(int i = 0; i < nFace;)
	{
		if(vertList[c] == -1)
		{
			i++;
		}
		else
		{
			nEdge++;
		}
		c++;
	}
	
	//set the step angle
	float step = angle / sFact;
	//convert it to radians
	step *= RADFACTOR;
	
	c = nVert*vSize*sFact;
	
	if(c > COORD_SIZE)
		return -1;
	
	//set out counters appropriately
	c = nVert*vSize;
	int c2 = 0;
	int c3 = 0;
	
	//for each step, we will create new vertices corresponding to 
	//those of the face before it and rotate them
	for(int i = 0; i < sFact; i++)
	{
		//create new vertices and rotate them
		//This is basically the same logic as with Extrude except
		//c2 goes through each vertex, even the ones created by c
		//c = c2 + number of vertices in the original list
		//c3 is the generic counter that'll count up to vSize
		for(int j = 0; j < nVert; j++)
		{
			c3 = 0;
			c2 = (j)*vSize; //i*nEdge + 
			
			int x = coord[c2++];
			int y = coord[c2++];
			int z = coord[c2++];
			
			coord[c++] = x*cos(step*(i+1)) + z*sin(step*(i+1)); c3++;
			coord[c++] = y; c3++;
			coord[c++] = z*cos(step*(i+1)) - x*sin(step*(i+1)); c3++;
			
			//fill other info
			while(c3 < vSize)
			{
				coord[c++] = coord[c2+c3++];
			}
		}
		
		//cout << "step: " << step*(i+1) << endl;
	}
	
	//Make sure faces won't overflow
	c = nEdge*5*sFact + 2*(nFace+nEdge);
	if(c > VERT_LIST_SIZE)
		return -1;
	
	//set counters appropriately
	c = nEdge + nFace;
	c2 = 0;
	c3 = 0;

	cout << endl;
	
	//draw faces
	for(int i = 0; i < nFace+nEdge; i++)
	{
		c2 = c;
		
		if(vertList[i+1] == -1)
		{
			vertList[c++] = vertList[i];
			vertList[c++] = vertList[i] + nEdge;
			vertList[c++] = vertList[c3] + nEdge;
			vertList[c++] = vertList[c3];
			vertList[c++] = -1;
			
			c3 = i+2;
			i++;
		}
		else
		{
			vertList[c++] = vertList[i];
			vertList[c++] = vertList[i] + nEdge;
			vertList[c++] = vertList[i+1] + nEdge;
			vertList[c++] = vertList[i+1];
			vertList[c++] = -1;
		}
		
		for(int j = 1; j < sFact; j++)
		{
			vertList[c++] = vertList[c2++] + nEdge;
			vertList[c++] = vertList[c2++] + nEdge;
			vertList[c++] = vertList[c2++] + nEdge;
			vertList[c++] = vertList[c2++] + nEdge;
			vertList[c++] = -1; c2++;
		}
	}

	//reset counters
	c2 = 0;
	c3 = 0;
	
	//draw endcap
	//Uses same logic as with Extrude
	for(int i = 0; i < nFace+nEdge; i++)
	{
		if(vertList[i] == -1)
		{
			vertList[c++] = -1;
		}
		else
		{
			vertList[c++] = vertList[i] + sFact*nEdge;
		}
	}
	
	//update number of faces and number of vertices
	nFace += sFact*nEdge + nFace;
	nVert *= sFact+1;
	
	//output the polyset
	outNewPolySet(name, vType, nVert, nFace, coord, vertList);
	
	//return 0
	return err;
}

//function gets the file name needed and parses it
int parsePolySet(string &name,
				 string &vType,
				 int &nVert,
				 int &nFace,
				 float coord[],
				 int vertList[])
{
	//file to read from
	ifstream file;
	
	//open the file
	file.open(name.c_str(), ifstream::in);
	if(!file.good())
	{
		cerr << "Error opening file!" << endl;
		return -1;
	}
	
	//set err to 0
	int err = 0;
	
	//parse the polyset
	err = parse_polyset(file, vType, nVert, nFace, coord, vertList);
	
	//close the file
	file.close();
	
	//return error
	return err;
}

//output a new polyset
int outNewPolySet(string &name,
				   string &vType,
				   int &nVert,
				   int &nFace,
				   float coord[],
				   int vertList[])
{
	//get the vertex size
	int vSize = get_vertex_size(vType);
	//bool for successful opening of a file
	bool write = true;
	//create a file (the dirty way)
	string name2 = "touch " + name;
	system(name2.c_str());
	
	//file the topen
	ofstream file;
	
	//open the file
	file.open(name.c_str(), ofstream::out);
	if(!file.good())
	{
		cerr << "Error writing to file!" << endl;
		write = false;
	}
	
	if(write == false)
		return 2;
	
	//output in standard out the polyset and type
	file << "PolySet " << vType << endl;
	//output number of vertices and faces
	file << nVert << " " << nFace << " ";
	
	int vertSize = get_vertex_size(vType);
	
	//output vertices
	for(int i = 0; i < nVert*vertSize; i++)
	{
		if(i % vSize == 0)
		{
			file << endl;
		}
		file << coord[i] << " ";
	}
	
	file << endl;
	
	//output faces
	int c = 0;
	for(int i = 0; i < nFace;)
	{
		if(vertList[c] == -1)
		{
			file << vertList[c++] << endl;
			i++;
		}
		else if(vertList[c] <= -2)
		{
			i = nFace + 1;
		}
		else
			file << vertList[c++] << " ";
	}
/*	
	//reset c and output to std out
	c = 0;
	//output in standard out the polyset and type
	cout << "PolySet " << vType << endl;
	//output number of vertices and faces
	cout << nVert << " " << nFace << " ";
	
	//output vertices
	for(int i = 0; i < nVert*vertSize; i++)
	{
		if(i % vSize == 0)
		{
			cout << endl;
		}
		cout << coord[i] << " ";
	}
	
	cout << endl;
	
	//output faces
	c = 0;
	for(int i = 0; i < nFace;)
	{
		if(vertList[c] == -1)
		{
			cout << vertList[c++] << endl;
			i++;
		}
		else if(vertList[c] <= -2)
		{
			i = nFace + 1;
		}
		else
			cout << vertList[c++] << " ";
	}
*/	
	return 0;
}