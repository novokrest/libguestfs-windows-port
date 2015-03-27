# Attempt to substitute XDR by ProtoBuf

top_srcdir = .
generator_dir = generator
guestfs_dir = src
daemon_dir = daemon

#test = -f TestMakefile
test = 

all: generator guestfs daemon

guestfs: generator
	$(MAKE) -C $(guestfs_dir) $(test)

daemon: generator
	$(MAKE) -C $(daemon_dir) $(test)

generator:
	$(MAKE) -C $(generator_dir) $(test)
	$(generator_dir)/$@

clean:
	$(MAKE) -C $(generator_dir) $(test) clean
	$(MAKE) -C $(guestfs_dir) $(test) clean
	$(MAKE) -C $(daemon_dir) $(test) clean

.PHONY: all clean generator guestfs daemon
