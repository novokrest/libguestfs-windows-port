#!/bin/bash

mkdir loop-dir
sudo mount -o loop,offset=1048576 disk.img loop-dir
