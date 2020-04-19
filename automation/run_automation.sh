#!/bin/bash
set -e
WORKING_DIR=$(find `pwd` -name `basename $0` -exec dirname {} \;)

cd $WORKING_DIR/..

echo "************** Creating build folder **************"
mkdir -p build && cd build

echo "************** Generating Makefiles **************"
cmake ..

echo "************** Compiling **************"
make
make install

echo "************** Running tests **************"
cd ../release
./median_structure_tests