#!/bin/sh

su
insmod kvm_ivshmem.ko
mknod --mode=666 /dev/ivshmem c 252 0 
su novokrestdeb

