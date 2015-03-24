# Attempt to substitute XDR by ProtoBuf

top_srcdir = .
generator_dir = generator
guestfs_dir = src

#test = -f TestMakefile
test = 

all: generator guestfs

guestfs: generator
	$(MAKE) -C $(guestfs_dir) $(test)

generator:
	$(MAKE) -C $(generator_dir) $(test)
	$(generator_dir)/$@

clean:
	$(MAKE) -C $(generator_dir) $(test) clean
	$(MAKE) -C $(guestfs_dir) $(test) clean

.PHONY: all clean guestfs generator
