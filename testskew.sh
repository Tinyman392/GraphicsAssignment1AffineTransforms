#!/bin/bash

make -f makeskew
rm rsphere.datSKEW rsphereS
./skew rsphere.dat 0.5 1
./3viewS rsphere.datSKEW > rsphereS
./rd_view rsphereS