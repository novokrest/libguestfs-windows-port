#!/bin/bash

su
rm -f /dev/ivshmem
rmmod kvm_ivshmem.ko
su novokrestdeb

