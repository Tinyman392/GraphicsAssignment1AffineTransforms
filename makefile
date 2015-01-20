All:
	g++ main.cc -o transforms -Wall -W -s functions.cc polyread.cc 
	
	g++ extrude.cc -o extrude -Wall -W -s functions.cc polyread.cc 
	
	g++ skew.cc -o skew -Wall -W -s functions.cc polyread.cc
	
	g++ sweep.cc -o sweep -Wall -W -s functions.cc polyread.cc 

	g++ twist.cc -o twist -Wall -W -s functions.cc polyread.cc 