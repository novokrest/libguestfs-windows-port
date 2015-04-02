# Based on libguestfs-1.28.5/appliance/Makefile.am

already_generated = make.sh \
	packagelist \
	supermin.d/excludefiles \
	supermin.d/hostfiles \
	supermin.d

libdir = /usr/local/lib
srcdir = .
fsdir = $(libdir)/guestfs
superminfsdir = $(libdir)/guestfs/supermin.d

fs =
superminfs = \
	supermin.d/base.tar.gz \
	supermin.d/daemon.tar.gz \
	supermin.d/excludefiles \
	supermin.d/hostfiles \
	supermin.d/init.tar.gz \
	supermin.d/packages \
	supermin.d/udev-rules.tar.gz

DAEMON_SUPERMIN_DIR = /sbin

all:  supermin.d/daemon.tar.gz supermin.d/excludefiles supermin.d/hostfiles supermin.d/init.tar.gz supermin.d/udev-rules.tar.gz

supermin.d/base.tar.gz supermin.d/packages: stamp-supermin
stamp-supermin: make.sh packagelist
	rm -f $@ supermin.d/base.tar.gz supermin.d/packages
	./make.sh
	$(MAKE) \
	  supermin.d/daemon.tar.gz \
	  supermin.d/excludefiles \
	  supermin.d/hostfiles \
	  supermin.d/init.tar.gz \
	  supermin.d/udev-rules.tar.gz
	touch $@

supermin.d/daemon.tar.gz: ../daemon/guestfsd guestfsd.suppressions guestfs_lvm_conf.aug guestfs_shadow.aug
	rm -f $@ $@-t
	rm -rf tmp-d
	mkdir -p tmp-d$(DAEMON_SUPERMIN_DIR) tmp-d/etc tmp-d/usr/share/guestfs
	ln ../daemon/guestfsd tmp-d$(DAEMON_SUPERMIN_DIR)/guestfsd
	ln $(srcdir)/guestfsd.suppressions tmp-d/etc/guestfsd.suppressions
	ln $(srcdir)/guestfs_lvm_conf.aug tmp-d/usr/share/guestfs/guestfs_lvm_conf.aug
	ln $(srcdir)/guestfs_shadow.aug tmp-d/usr/share/guestfs/guestfs_shadow.aug
	( cd tmp-d && tar zcf - * ) > $@-t
	rm -r tmp-d
	mv $@-t $@

# Note we must avoid touching supermin.d if possible, so don't create
# the temporary files inside the supermin.d directory.

supermin.d/init.tar.gz: init
	rm -f $@ $@-t
	( cd $(srcdir) && tar zcf - init ) > $@-t
	mv $@-t $@

# We should put this file in /lib/udev/rules.d, but put it in /etc so
# we don't have to deal with all the UsrMove crap in Fedora.
supermin.d/udev-rules.tar.gz: 99-guestfs-serial.rules
	rm -f $@ $@-t
	rm -rf tmp-u
	mkdir -p tmp-u/etc/udev/rules.d
	for f in $^; do ln $$f tmp-u/etc/udev/rules.d/$$(basename $$f); done
	( cd tmp-u && tar zcf - etc ) > $@-t
	rm -r tmp-u
	mv $@-t $@

PACKAGELIST_CPP_FLAGS = -D$(DISTRO)=1 -DEXTRA_PACKAGES="$(EXTRA_PACKAGES)"

packagelist: packagelist.in Makefile
	m4 $(PACKAGELIST_CPP_FLAGS) $< | \
	grep -v '^[[:space:]]*$$' | grep -v '^#' > $@-t
	cmp -s $@ $@-t || mv $@-t $@
	rm -f $@-t

$@supermin.d/excludefiles: excludefiles.in Makefile
	m4 $(PACKAGELIST_CPP_FLAGS) $< | \
	grep -v '^[[:space:]]*$$' | grep -v '^#' > excludefiles-t
	cmp -s $@ excludefiles-t || mv excludefiles-t $@
	rm -f excludefiles-t

supermin.d/hostfiles: hostfiles.in Makefile
	m4 $(PACKAGELIST_CPP_FLAGS) $< | \
	grep -v '^[[:space:]]*$$' | grep -v '^#' > hostfiles-t
	cmp -s $@ hostfiles-t || mv hostfiles-t $@
	rm -f hostfiles-t

# Make clean.

CLEANFILES = \
	*~ \
	libguestfs-make-fixed-appliance.1 \
	stamp-libguestfs-make-fixed-appliance.pod

DISTCLEANFILES = \
	stamp-supermin

clean:
	rm -f $(CLEANFILES) $(DISTCLEANFILES)

