#!/bin/bash

make -f maketwist
rm rsphere.datTWIST rsphereT
./twist rsphere.dat 30
./3viewS rsphere.datTWIST > rsphereT
./rd_view rsphereT