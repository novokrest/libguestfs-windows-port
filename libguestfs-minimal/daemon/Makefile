# libguestfs-daemon
# Copyright (C) 2011 Red Hat Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

CC = gcc

SOURCES = \
	9p.c \
	acl.c \
	actions.h \
	available.c \
	augeas.c \
	base64.c \
	blkdiscard.c \
	blkid.c \
	blockdev.c \
	btrfs.c \
	cap.c \
	checksum.c \
	cmp.c \
	command.c \
	compress.c \
	copy.c \
	cpio.c \
	cpmv.c \
	daemon.h \
	dd.c \
	debug.c \
	devsparts.c \
	df.c \
	dir.c \
	dmesg.c \
	dropcaches.c \
	du.c \
	echo-daemon.c \
	ext2.c \
	fallocate.c \
	file.c \
	findfs.c \
	fill.c \
	find.c \
	fsck.c \
	fstrim.c \
	glob.c \
	grep.c \
	grub.c \
	guestfsd.c \
	headtail.c \
	hexdump.c \
	hotplug.c \
	hivex.c \
	htonl.c \
	initrd.c \
	inotify.c \
	internal.c \
	is.c \
	isoinfo.c \
	journal.c \
	labels.c \
	ldm.c \
	link.c \
	ls.c \
	luks.c \
	lvm.c \
	lvm-filter.c \
	md.c \
	mkfs.c \
	mknod.c \
	mktemp.c \
	modprobe.c \
	mount.c \
	mountable.c \
	names.c \
	ntfs.c \
	ntfsclone.c \
	optgroups.c \
	optgroups.h \
	parted.c \
	pingdaemon.c \
	proto.c \
	readdir.c \
	realpath.c \
	rename.c \
	rsync.c \
	scrub.c \
	selinux.c \
	sfdisk.c \
	sleep.c \
	stat.c \
	statvfs.c \
	strings.c \
	stubs.c \
	swap.c \
	sync.c \
	syslinux.c \
	tar.c \
	truncate.c \
	umask.c \
	upload.c \
	utimens.c \
	utsname.c \
	uuids.c \
	wc.c \
	xattr.c \
	xfs.c \
	zero.c \
	zerofree.c

OBJECTS = $(SOURCES:%.c=%.o)

top_srcdir = ..
top_builddir = ..

CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/gnulib/lib \
	-I$(top_builddir)/gnulib/lib \
	-I$(top_srcdir)/src \
	-I$(top_builddir)/src

WARN_CFLAGS =  -W -Wabi -Waddress -Waggressive-loop-optimizations -Wall -Warray-bounds -Wattributes -Wbad-function-cast -Wbuiltin-macro-redefined -Wcast-align -Wchar-subscripts -Wclobbered -Wcomment -Wcomments -Wcoverage-mismatch -Wcpp -Wdeprecated -Wdeprecated-declarations -Wdisabled-optimization -Wdiv-by-zero -Wdouble-promotion -Wempty-body -Wendif-labels -Wenum-compare -Wextra -Wformat-contains-nul -Wformat-extra-args -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wformat-zero-length -Wfree-nonheap-object -Wignored-qualifiers -Wimplicit -Wimplicit-function-declaration -Wimplicit-int -Winit-self -Wint-to-pointer-cast -Winvalid-memory-model -Winvalid-pch -Wjump-misses-init -Wlogical-op -Wmain -Wmaybe-uninitialized -Wmissing-braces -Wmissing-declarations -Wmissing-field-initializers -Wmissing-include-dirs -Wmissing-parameter-type -Wmissing-prototypes -Wmultichar -Wnarrowing -Wnested-externs -Wnonnull -Wold-style-declaration -Wold-style-definition -Woverflow -Woverride-init -Wpacked-bitfield-compat -Wparentheses -Wpointer-arith -Wpointer-sign -Wpointer-to-int-cast -Wpragmas -Wreturn-local-addr -Wreturn-type -Wsequence-point -Wsizeof-pointer-memaccess -Wstack-protector -Wstrict-aliasing -Wstrict-overflow -Wstrict-prototypes -Wsuggest-attribute=format -Wsuggest-attribute=noreturn -Wswitch -Wsync-nand -Wtrampolines -Wtrigraphs -Wtype-limits -Wuninitialized -Wunknown-pragmas -Wunused -Wunused-but-set-parameter -Wunused-but-set-variable -Wunused-function -Wunused-label -Wunused-local-typedefs -Wunused-macros -Wunused-parameter -Wunused-result -Wunused-value -Wunused-variable -Wvarargs -Wvariadic-macros -Wvector-operation-performance -Wvolatile-register-var -Wwrite-strings -Wnormalized=nfc -Wno-unused-parameter -Wno-missing-field-initializers -fdiagnostics-show-option -Wframe-larger-than=10000
WERROR_CFLAGS = 
AUGEAS_CFLAGS = -I/usr/include/libxml2
HIVEX_CFLAGS = 
SD_JOURNAL_CFLAGS = 
YAJL_CFLAGS = 
PCRE_CFLAGS = 

CFLAGS = \
	$(WARN_CFLAGS) $(WERROR_CFLAGS) \
	$(AUGEAS_CFLAGS) \
	$(HIVEX_CFLAGS) \
	$(SD_JOURNAL_CFLAGS) \
	$(YAJL_CFLAGS) \
	$(PCRE_CFLAGS)

ACL_LIBS = 
CAP_LIBS = 
YAJL_LIBS = 
SELINUX_LIBS = 
AUGEAS_LIBS = -laugeas
HIVEX_LIBS = 
SD_JOURNAL_LIBS = 
GETADDRINFO_LIB = 
HOSTENT_LIB = 
INET_NTOP_LIB = 
LIBSOCKET = 
LIB_CLOCK_GETTIME = 
LIBINTL = 
SERVENT_LIB = 
PCRE_LIBS = -lpcre

LIBS = 	\
	$(ACL_LIBS) \
	$(CAP_LIBS) \
	$(YAJL_LIBS) \
	$(SELINUX_LIBS) \
	$(AUGEAS_LIBS) \
	$(HIVEX_LIBS) \
	$(SD_JOURNAL_LIBS) \
	$(GETADDRINFO_LIB) \
	$(HOSTENT_LIB) \
	$(INET_NTOP_LIB) \
	$(LIBSOCKET) \
	$(LIB_CLOCK_GETTIME) \
	$(LIBINTL) \
	$(SERVENT_LIB) \
	$(PCRE_LIBS)

DAEMON = guestfsd.exe
GPERF = gperf

all: $(DAEMON)

$(DAEMON): $(OBJECTS) errnostring-gperf.o guestfs_protocol.pb-c.o
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c errnostring-gperf.h guestfs_protocol
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

errnostring-gperf.h: errnostring-gperf.gperf
	rm -f $@
	$(GPERF) -t $< > $@-t
	mv $@-t $@

errnostring-gperf.o: errnostring-gperf.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

guestfs_protocol:
	cp $(top_srcdir)/src/$@.pb-c.h $(top_srcdir)/daemon/
	cp $(top_srcdir)/src/$@.pb-c.c $(top_srcdir)/daemon/
	cp $(top_srcdir)/src/$@_typedefs.h $(top_srcdir)/daemon/

clean:
	rm -f *.o

.PHONY: all clean guestfs_protocol
