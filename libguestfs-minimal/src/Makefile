top_srcdir = ..
top_builddir = ..
libdir = /usr/local/lib

CC = gcc -std=gnu99 -std=gnu99
PROTOC = protoc-c

WARN_CFLAGS = -w -W -Wabi -Waddress -Waggressive-loop-optimizations -Wall -Warray-bounds -Wattributes -Wbad-function-cast -Wbuiltin-macro-redefined -Wcast-align -Wchar-subscripts -Wclobbered -Wcomment -Wcomments -Wcoverage-mismatch -Wcpp -Wdeprecated -Wdeprecated-declarations -Wdisabled-optimization -Wdiv-by-zero -Wdouble-promotion -Wempty-body -Wendif-labels -Wenum-compare -Wextra -Wformat-contains-nul -Wformat-extra-args -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wformat-zero-length -Wfree-nonheap-object -Wignored-qualifiers -Wimplicit -Wimplicit-function-declaration -Wimplicit-int -Winit-self -Wint-to-pointer-cast -Winvalid-memory-model -Winvalid-pch -Wjump-misses-init -Wlogical-op -Wmain -Wmaybe-uninitialized -Wmissing-braces -Wmissing-declarations -Wmissing-field-initializers -Wmissing-include-dirs -Wmissing-parameter-type -Wmissing-prototypes -Wmultichar -Wnarrowing -Wnested-externs -Wnonnull -Wold-style-declaration -Wold-style-definition -Woverflow -Woverride-init -Wpacked-bitfield-compat -Wparentheses -Wpointer-arith -Wpointer-sign -Wpointer-to-int-cast -Wpragmas -Wreturn-local-addr -Wreturn-type -Wsequence-point -Wsizeof-pointer-memaccess -Wstack-protector -Wstrict-aliasing -Wstrict-overflow -Wstrict-prototypes -Wsuggest-attribute=format -Wsuggest-attribute=noreturn -Wswitch -Wsync-nand -Wtrampolines -Wtrigraphs -Wtype-limits -Wuninitialized -Wunknown-pragmas -Wunused -Wunused-but-set-parameter -Wunused-but-set-variable -Wunused-function -Wunused-label -Wunused-local-typedefs -Wunused-macros -Wunused-parameter -Wunused-result -Wunused-value -Wunused-variable -Wvarargs -Wvariadic-macros -Wvector-operation-performance -Wvolatile-register-var -Wwrite-strings -Wnormalized=nfc -Wno-unused-parameter -Wno-missing-field-initializers -fdiagnostics-show-option -Wframe-larger-than=10000
WERROR_CFLAGS = 
GCC_VISIBILITY_HIDDEN = -fvisibility=hidden

PCRE_CFLAGS = 
LIBVIRT_CFLAGS = 
LIBXML2_CFLAGS = -I/usr/include/libxml2
YAJL_CFLAGS = 
PROTOBUF_CFLAGS = `pkg-config --cflags libprotobuf-c`

PCRE_LIBS = -lpcre
MAGIC_LIBS = 
LIBVIRT_LIBS = 
LIBXML2_LIBS = -lxml2
SELINUX_LIBS = 
YAJL_LIBS = 
GETADDRINFO_LIB = 
HOSTENT_LIB = 
INET_NTOP_LIB = 
LIBSOCKET = 
LIB_CLOCK_GETTIME = 
LTLIBINTL = 
LTLIBTHREAD = 
LTLIBICONV = 
SERVENT_LIB = 
PROTOBUF_LIB = `pkg-config --libs libprotobuf-c`

GUESTFS_CPPFLAGS = \
	-DGUESTFS_DEFAULT_PATH='"$(libdir)/guestfs"' \
	-DGUESTFS_WARN_DEPRECATED=1 \
	-DGUESTFS_PRIVATE=1 \
	-DLIBOSINFO_DB_PATH='"$(datadir)/libosinfo/db"' \
	-I$(top_srcdir) \
	-I$(top_srcdir)/gnulib/lib -I$(top_builddir)/gnulib/lib

GUESTFS_CFLAGS = \
	$(WARN_CFLAGS) $(WERROR_CFLAGS) \
	$(GCC_VISIBILITY_HIDDEN) \
	$(PCRE_CFLAGS) \
	$(LIBVIRT_CFLAGS) \
	$(LIBXML2_CFLAGS) \
	$(YAJL_CFLAGS) \
	$(PROTOBUF_CFLAGS)

GUESTFS_LIBS = \
	$(PCRE_LIBS) $(MAGIC_LIBS) \
	$(LIBVIRT_LIBS) $(LIBXML2_LIBS) \
	$(SELINUX_LIBS) \
	$(YAJL_LIBS) \
	$(GETADDRINFO_LIB) \
	$(HOSTENT_LIB) \
	$(INET_NTOP_LIB) \
	$(LIBSOCKET) \
	$(LIB_CLOCK_GETTIME) \
	$(LTLIBINTL) \
	$(LTLIBTHREAD) \
	$(LTLIBICONV) \
	$(SERVENT_LIB) \
	$(PROTOBUF_LIB)

GUESTFS_INCLUDE = \
	guestfs.h \
	guestfs-internal.h \
	guestfs-internal-all.h \
	guestfs-internal-frontend.h \
	guestfs-internal-frontend-cleanups.h \
	guestfs_protocol.pb-c.h \
	guestfs_protocol_typedefs.h

GUESTFS_SOURCES = \
	actions-0.c \
	actions-1.c \
	actions-2.c \
	actions-3.c \
	actions-4.c \
	actions-5.c \
	actions-6.c \
	actions-support.c \
	actions-variants.c \
	alloc.c \
	appliance.c \
	bindtests.c \
	canonical-name.c \
	command.c \
	conn-socket.c \
	create.c \
	dbdump.c \
	drives.c \
	errors.c \
	event-string.c \
	events.c \
	file.c \
	filearch.c \
	fuse.c \
	guestfs_protocol.pb-c.c \
	guid.c \
	handle.c \
	info.c \
	inspect.c \
	inspect-apps.c \
	inspect-fs.c \
	inspect-fs-cd.c \
	inspect-fs-unix.c \
	inspect-fs-windows.c \
	inspect-icon.c \
	journal.c \
	launch.c \
	launch-direct.c \
	launch-libvirt.c \
	launch-uml.c \
	launch-unix.c \
	libvirt-auth.c \
	libvirt-domain.c \
	listfs.c \
	lpj.c \
	match.c \
	osinfo.c \
	private-data.c \
	proto.c \
	stringsbuf.c \
	structs-compare.c \
	structs-copy.c \
	structs-free.c \
	tmpdirs.c 

ERRNOSTRING_SOURCES = \
	errnostring-gperf.c \
	errnostring.h \
	errnostring.c

PROTOCOL_SOURCES = \
	guestfs_protocol.pb-c.c \
	guestfs_protocol.pb-c.h \
	guestfs_protocol_typedefs.h

GUESTFS_OBJECTS = $(GUESTFS_SOURCES:.c=.o)

GUESTFS_LIBRARY = guestfs

all: $(GUESTFS_LIBRARY)

$(GUESTFS_LIBRARY): $(GUESTFS_OBJECTS) 
	$(CC) -shared -o lib$@.so $^ $(GUESTFS_LIBS)

%.o: %.c
	$(CC) -c $(GUESTFS_CPPFLAGS) $(GUESTFS_CFLAGS) -fPIC -o $@ $<

errnostring-gperf.c: errnostring-gperf.gperf
	rm -f $@
	$(GPERF) -t $< > $@-t
	mv $@-t $@

guestfs_protocol.pb-c.c: guestfs_protocol.proto
	$(PROTOC) --c_out=. $<

clean:
	rm -f *.o

.PHONY: all clean
