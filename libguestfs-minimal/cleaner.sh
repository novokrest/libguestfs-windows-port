#!/bin/bash

make clean
rm -f *~
cd generator && ./cleaner.sh 
cd ..
cd src && ./cleaner.sh 
cd ..
