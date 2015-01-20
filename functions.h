#ifndef functions_h
#define functions_h

#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;

/*********************************************************************/
//Function declarations

//asks user for file name, returns that file name
string getFileName();
//parses PolySet using polyread by opening file named name.
//Fills the parameters with information taken from polyread
int parsePolySet(string &name,
				 string &vType,
				 int &nVert,
				 int &nFace,
				 float coord[],
				 int vertList[]);
//Takes in the parameters needed to for the polyset and outputs it
//to a file and to standard output
int outNewPolySet(string &name,
				   string &vType,
				   int &nVert,
				   int &nFace,
				   float coord[],
				   int vertList[]);
//skews a given polyset over the x y axis by a factor of sx and sy
int skew(string &name, float sx, float sy);
//twists a given polyset based on an angle
int twist(string &name, float angle);
//extrudes a given polyset by xFact units
int extrude(string &name, float xFact);
//sweeps a given polyset in sFact steps at a total angle of angle
int sweep(string &name, int sFact, float angle);
/*********************************************************************/

#endif