#!/bin/bash

#-netdev user,id=network0 -device e1000,netdev=network0

QEMU=qemu-system-x86_64
CLI_KVM=--enable-kvm
#CLI_KERNEL=-kernel vmlinuz
#CLI_INITRD=-initrd initrd
CLI_NETWORK='-net nic -net user'
CLI_DISKIMG='-hda disk.img'
CLI_IVSHMEM='-device ivshmem,shm=testshm,size=1M'
#CLI_APPEND='-append "root=/dev/sda1"'

CMD_RUN=`$QEMU $CLI_KVM $CLI_KERNEL $CLI_INITRD $CLI_NETWORK $CLI_DISKIMG $CLI_IVSHMEM $CLI_APPEND`

