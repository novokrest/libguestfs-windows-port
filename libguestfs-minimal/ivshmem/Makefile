src_dir = .
uio_dir = $(src_dir)/uio

all: install

install: uio
	sudo cp $(uio_dir)/uio_ivshmem.ko /lib/modules/`uname -r`/kernel/drivers/uio/
	sudo depmod -a	

uio:
	$(MAKE) -C $(uio_dir)

clean:
	$(MAKE) -C $(uio_dir) clean
	rm -f /lib/modules/`uname -r`/kernel/drivers/uio/uio_ivshmem.ko

.PHONY: all install uio clean
