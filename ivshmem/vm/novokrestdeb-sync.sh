#!/bin/bash

SYNC_DIR=novokrestdeb

if [ ! -d "$SYNC_DIR" ]; then
  mkdir $SYNC_DIR
fi

if [ ! -d "loop-dir" ]; then
  mkdir loop-dir
fi

sudo mount -o loop,offset=1048576 disk.img loop-dir

cp -r loop-dir/home/novokrestdeb/* $SYNC_DIR

sudo umount loop-dir

if [ -d "loop-dir" ]; then 
  rm -r loop-dir
fi
