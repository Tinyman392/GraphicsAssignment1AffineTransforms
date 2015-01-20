############
# F1 Racer #
############

Display "F1 Racer" "Screen" "rgbdouble"

Background 0.25 0.25 0.25
CameraAt 13 18 7
CameraEye -10 50 30
CameraUp 0 0 1
CameraFOV 20

#Generic Axle - Needs to be scaled
ObjectBegin "Axle"
	XformPush
		Color 0.75 0.75 0.75
		Cylinder 0.5 -0.5 0.5 360
	XformPop
ObjectEnd

ObjectBegin "RearAxle"
	XformPush
		Color 0.75 0.75 0.75
		Cylinder 0.5 -2 2 360
	XformPop
ObjectEnd

ObjectBegin "FrontAxle"
	XformPush
		Color 0.75 0.75 0.75
		Cylinder 0.5 -1.85 1.85 360
	XformPop
ObjectEnd

ObjectBegin "Connector"
	XformPush
		Color 1 1 0
		Sphere 1 -1 1 360
	XformPop
ObjectEnd

ObjectBegin "RearWheel"
	XformPush
		Color 0 0 0
		Cylinder 2 -1 1 360
	XformPop
ObjectEnd

ObjectBegin "FrontWheel"
	XformPush
		Color 0 0 0
		Cylinder 1.5 -0.75 0.75 360
	XformPop
ObjectEnd

ObjectBegin "Car"
	#Draw the main car
	
	PolySet "PC"
	80 60
	#
	#upper points
	#
	#"left" side
	0 	1	1		1	0	0	#0
	2 	1	2		1	0	0	#1
	6 	1 	2.5		1	0	0	#2
	11	1	2.5		1	0	0	#3
	13 	1	3.25	1	0	0	#4
	13 	2	2.5		1	0	0	#5
	16 	1	2.5		1	0	0	#6
	20 	1	1		1	0	0	#7
	19 	2	1.5		1	0	0	#8
	17 	3	2		1	0	0	#9
	14 	4	2.5		1	0	0	#10
	13 	4	2.5		1	0	0	#11
	11 	3	2.5		1	0	0	#12
	10 	2	2.5		1	0	0	#13
	2 	3.5	1.5		1	0	0	#14
	2 	4	1.5		1	0	0	#15
	0 	4	1		1	0	0	#16
	0 	3.5	1		1	0	0	#17
	#"right" side
	0 	-1	1		1	0	0	#18
	2 	-1	2		1	0	0	#19
	6 	-1 	2.5		1	0	0	#20
	11	-1	2.5		1	0	0	#21
	13 	-1	3.25	1	0	0	#22
	13 	-2	2.5		1	0	0	#23
	16 	-1	2.5		1	0	0	#24
	20 	-1	1		1	0	0	#25
	19 	-2	1.5		1	0	0	#26
	17 	-3	2		1	0	0	#27
	14 	-4	2.5		1	0	0	#28
	13 	-4	2.5		1	0	0	#29
	11 	-3	2.5		1	0	0	#30
	10 	-2	2.5		1	0	0	#31
	2 	-3.5	1.5	1	0	0	#32
	2 	-4	1.5		1	0	0	#33
	0 	-4	1		1	0	0	#34
	0 	-3.5	1	1	0	0	#35
	#center points
	10	0	2.5		1	0	0	#36
	13	0	6		1	0	0	#37
	16	0	4.5		1	0	0	#38
	19	0	2		1	0	0	#39
	#
	#lower points 
	#
	#lower vertex = upper vertex + 40
	#
	0 	1	0		1	0	0	#40
	2 	1	0		1	0	0	#41
	6 	1 	0		1	0	0	#42
	11	1	1		1	0	0	#43
	13 	1	1		1	0	0	#44
	13 	2	0		1	0	0	#45
	16 	1	0		1	0	0	#46
	20 	1	0		1	0	0	#47
	19 	2	0		1	0	0	#48
	17 	3	0		1	0	0	#49
	14 	4	0		1	0	0	#50
	13 	4	0		1	0	0	#51
	11 	3	0		1	0	0	#52
	10 	2	0		1	0	0	#53
	2 	3.5	0.5		1	0	0	#54
	2 	4	0.5		1	0	0	#55
	0 	4	0.5		1	0	0	#56
	0 	3.5	0.5		1	0	0	#57
	#"right" side
	0 	-1	0		1	0	0	#58
	2 	-1	0		1	0	0	#59
	6 	-1 	0		1	0	0	#60
	11	-1	1		1	0	0	#61
	13 	-1	1		1	0	0	#62
	13 	-2	0		1	0	0	#63
	16 	-1	0		1	0	0	#64
	20 	-1	0		1	0	0	#65
	19 	-2	0		1	0	0	#66
	17 	-3	0		1	0	0	#67
	14 	-4	0		1	0	0	#68
	13 	-4	0		1	0	0	#69
	11 	-3	0		1	0	0	#70
	10 	-2	0		1	0	0	#71
	2 	-3.5	0.5	1	0	0	#72
	2 	-4	0.5		1	0	0	#73
	0 	-4	0.5		1	0	0	#74
	0 	-3.5	0.5	1	0	0	#75
	#center points
	10	0	1		1	0	0	#76
	13	0	1		1	0	0	#77
	16	0	0		1	0	0	#78
	19	0	0		1	0	0	#79
	#
	#Make Faces
	#
	#
	#Top
	#
	#Center
	19 18 0 1 -1
	2 1 19 20 -1
	20 31 13 2 -1
	39 25 7 -1
	#Left
	36 3 5 10 11 12 13 -1
	37 38 6 4 -1
	3 4 5 -1
	5 6 4 -1
	38 39 6 -1
	5 6 10 -1
	6 9 10 -1
	6 8 9 -1
	6 39 8 -1
	39 7 8 -1
	14 15 16 17 -1
	#Right
	36 31 30 29 28 23 21 -1
	37 22 24 38 -1
	23 22 21 -1
	22 23 24 -1
	24 39 38 -1
	28 24 23 -1
	28 27 24 -1
	27 26 24 -1
	24 26 39 -1
	39 26 25 -1
	35 34 33 32 -1
	#
	#Sides
	#
	#Left
	1 0 40 41 -1
	2 1 41 42 -1
	13 2 42 53 -1 
	12 13 53 52 -1
	11 12 52 51 -1
	10 11 51 50 -1
	9 10 50 49 -1
	8 9 49 48 -1
	7 8 48 47 -1
	17 14 54 57 -1
	14 15 55 54 -1
	15 16 56 55 -1
	16 17 57 56 -1
	#Right
	18 19 59 58 -1
	19 20 60 59 -1
	20 31 71 60 -1
	31 30 70 71 -1
	30 29 69 70 -1
	29 28 68 69 -1
	28 27 67 68 -1 
	27 26 66 67 -1
	26 25 65 66 -1
	34 33 73 74 -1
	33 32 72 73 -1
	32 35 75 72 -1
	35 34 74 75 -1
	#Center
	0 18 58 40 -1
	4 22 62 64 -1
	7 25 65 47 -1
	37 22 4 -1
	#
	#Bottom
	#
	76 61 62 44 43 -1
	40 41 42 53 52 51 50 49 48 47 65 66 67 68 69 70 71 60 59 58 -1
	40 41 54 57 -1
	59 58 75 72 -1
ObjectEnd

WorldBegin
	
	#
	# The wheels and axles are my example of:
	# -Branches
	# -Chains
	#
	# The Car will sit on top of this all, so if you want
	# 	to see it, comment out the Car's ObjectInstance 
	#	that is on the bottom of the WorldBlock
	#
	
	XformPush
		#Start at rear axle and move forward
		Translate 20 0 1
		Rotate "Y" 90
		
		ObjectInstance "Connector"
		
		#First branch: rear right wheel
		XformPush
			#Scale
			Translate 0 0 2
			ObjectInstance "RearAxle"
			
			#Scale back
			Translate 0 0 2
			ObjectInstance "RearWheel"
		XformPop
		
		#Second branch: rear left wheel
		XformPush
			#Scale
			Translate 0 0 -2
			ObjectInstance "RearAxle"
			
			#Scale back
			Translate 0 0 -2
			ObjectInstance "RearWheel"
		XformPop
		
		#Third branch: center axle
		XformPush
			Rotate "X" -90
			
			Translate 0 0 3
			XformPush
				Scale 1 1 6
				ObjectInstance "Axle"
			XformPop
			
			Translate 0 0 3
			ObjectInstance "Connector"
			
			Translate 0 0 4.75
			XformPush
				Scale 1 1 9.5
				ObjectInstance "Axle"
			XformPop
			
			Translate 0 0 4.75
			ObjectInstance "Connector"
			
			Rotate "X" 90
			
			#Forth branch: front right wheel
			XformPush
				Translate 0 0 1.875
				ObjectInstance "FrontAxle"
				
				Translate 0 0 1.875
				ObjectInstance "FrontWheel"
			XformPop
			
			#Fifth branch: front left wheel
			XformPush
				Translate 0 0 -1.875
				
				ObjectInstance "FrontAxle"
				
				
				Translate 0 0 -1.875
				ObjectInstance "FrontWheel"
			XformPop
		XformPop
		
	XformPop
	
	XformPush
	#Translate 12 0 0
	Scale 20 20 20
	FarLight 1 1 -1 1 1 1 5
	FarLight 1 -1 -1 1 1 1 5
	FarLight 1 1 1 1 1 1 5
	FarLight 1 -1 1 1 1 1 5
	
	FarLight 0 1 -1 1 1 1 5
	FarLight 0 -1 -1 1 1 1 5
	FarLight 0 1 1 1 1 1 5
	FarLight 0 -1 1 1 1 1 5
	XformPop
	
	Surface "metal"
	Ka 0.5
	Kd 0.5
	Ks 0.5
	
	Translate 20 20 0
	Rotate "Z" -90
	ObjectInstance "Car"
	
	#Surface "plastic"
	#Ka 0.75
	#Kd 0.75
	#Ks 0.25
	#Color .75 0 0
	#Translate 12 0 3
	#Sphere 1 -2 2 360
	
WorldEnd