#!/bin/bash

make -f makesweep
rm shapes.datSWEEP shapesS
./sweep shapes.dat 256 270
./3viewS shapes.datSWEEP > shapesS
./rd_view shapesS