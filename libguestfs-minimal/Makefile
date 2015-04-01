# Attempt to substitute XDR by ProtoBuf

top_srcdir = .
generator_dir = generator
guestfs_dir = src
daemon_dir = daemon
appliance_dir = appliance

#test = -f TestMakefile
test = 

all: generator guestfs daemon appliance

guestfs: generator
	$(MAKE) -C $(guestfs_dir) $(test)

daemon: generator
	$(MAKE) -C $(daemon_dir) $(test)

generator:
	$(MAKE) -C $(generator_dir) $(test)
	$(generator_dir)/$@.exe

appliance:
	$(MAKE) -C $(appliance_dir) $(test)

clean:
	$(MAKE) -C $(generator_dir) clean $(test)
	$(MAKE) -C $(guestfs_dir) clean $(test)
	$(MAKE) -C $(daemon_dir) clean $(test)
	$(MAKE) -C $(appliance_dir) clean $(test)

.PHONY: all clean generator guestfs daemon appliance
