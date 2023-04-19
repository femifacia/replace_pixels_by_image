#!/usr/bin/bash

rm -rfv build
mkdir build
cd build
cmake ../
make
cd ..