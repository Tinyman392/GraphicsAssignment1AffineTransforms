#!/bin/bash

make

#./3view shapes.dat > shapes.rd
#./rd_view shapes.rd

#./3view rsphere.dat > rsphere.rd
#./rd_view rsphere.rd

./extrude shapes.dat 5
./3viewS shapes.datEXTRUDE > shapesE
./rd_view shapesE

./skew rsphere.dat 0.5 1
./3view rsphere.datSKEW > rsphereS
./rd_view rsphereS

./sweep shapes.dat 512 270
./3viewS shapes.datSWEEP > shapesS
./rd_view shapesS

./twist rsphere.dat 15
./3view rsphere.datTWIST > rsphereT
./rd_view rsphereT

rm rsphere.datSKEW rsphere.datTWIST shapes.datEXTRUDE shapes.datSWEEP
rm rsphereS rsphereT shapesE shapesS
rm shapes.rd rsphere.rd