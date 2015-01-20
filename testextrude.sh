#!/bin/bash

make -f makeextrude
rm shapes.datEXTRUDE shapesE
./extrude shapes.dat 5
./3viewS shapes.datEXTRUDE > shapesE
./rd_view shapesE