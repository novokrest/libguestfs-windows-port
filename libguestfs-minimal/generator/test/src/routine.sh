#!/bin/bash

cd ../../ &&
make clean && make &&
./generator.exe &&
cd test/src/ &&
make clean && make
