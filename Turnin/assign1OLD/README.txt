The following files are inside of this tar ball if everything went well:
	Car.rd
	functions.cc
	functions.h
	main.cc
	make
	polyread.cc
	polyread.h

The explanations of each file go as follows:

Car.rd
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

main.cc
	Runs the main program that uses a menu-based system to test the 4 
	functions.  On completion, you should have a new file containing a 
	Polyset as well as the Polyset in standard out.

polyread.cc polyread.h
	Originally your polyread.cc with added constants.
	
	I had some issues linking functions.cc and polyread.cc so I had to 
	split them up into two files, one header for each.  Outside adding the
	constants and splitting off declarations into polyread.h, the 
	polyread.cc is not altered.