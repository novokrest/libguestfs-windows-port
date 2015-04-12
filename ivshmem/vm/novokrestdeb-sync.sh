#!/bin/bash

SYNC_DIR=novokrestdeb

if [ -d "$SYNC_DIR" ]; then
  rm -rf $SYNC_DIR
fi

mkdir $SYNC_DIR

if [ ! -d "loop-dir" ]; then
  mkdir loop-dir
fi

sudo mount -o loop,offset=1048576 disk.img loop-dir

cp -r loop-dir/home/novokrestdeb/* $SYNC_DIR

sudo umount loop-dir

if [ -d "loop-dir" ]; then 
  rm -r loop-dir
fi
