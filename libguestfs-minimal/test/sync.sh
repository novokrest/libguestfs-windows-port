#!/bin/bash

cp ../src/libmyguestfs.so .
rm -f guestfs.h && cp ../src/guestfs.h .
make clean
make
