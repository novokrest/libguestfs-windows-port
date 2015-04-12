#!/bin/bash

cd .. && cd generator &&
make clean && make &&
cd .. && generator/generator.exe &&
cd daemon && make
