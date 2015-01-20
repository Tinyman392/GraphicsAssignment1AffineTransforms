The following files are inside of this tar ball if everything went well:
	Car.rd
	functions.cc
	functions.h
	make
	polyread.cc
	polyread.h
	extrude.cc
	skew.cc
	sweep.cc
	twist.cc
	testall.sh

The explanations of each file go as follows:

Car.rd -> Turned in on time!
	Contains my instance of a 50+ vertex PolySet (80 total for this one) 
	It generates an F1-esque race car without a spoiler.  
	
	Additionally, it also contains my branching and linking which is the 
	skeleton of the vehicle (wheels, axles, driveshaft?, etc.).  THE CAR 
	COVERS THIS, PLEASE COMMENT OUT LINE 343 TO SEE THE BRANCHING AND 
	LINKING!  For reference, line 343 is:
	
		ObjectInstance "Car"

functions.cc and functions.h
	Contain my functions that will skew, twist, extrude, and sweep.
	Additional functions included to make it all work.

polyread.cc polyread.h
	Originally your polyread.cc with added constants.
	
	I had some issues linking functions.cc and polyread.cc so I had to 
	split them up into two files, one header for each.  Outside adding the
	constants and splitting off declarations into polyread.h, the 
	polyread.cc is not altered.

testall.sh
	Shell script that will compile all executables (4 in total) and test
	the executables using some data.  Uses the default dat files that are
	supplied on the course website.  For extrude and sweep, utilizes the 
	shapes.dat file while the other two use the rsphere.dat file
	
	The script also cleans up all files that are created by anything at the 
	end.  Comment out if you don't want this.

extrude.cc skew.cc sweep.cc twist.cc
	These are contain the main files for their respective file names.  

make
	Uses g++ to output 4 executable files for use.  