# Attempt to substitute XDR by ProtoBuf

GUESTFS_HEADERS = \
  errnostring.h \
  guestfs.h \
  guestfs-internal.h \
  guestfs-internal-actions.h \
  guestfs-internal-all.h \
  guestfs-internal-frontend.h \
  guestfs-internal-frontend-cleanups.h \
  guestfs_protocol.h \

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
  errnostring-gperf.c \
  errors.c \
  event-string.c \
  events.c \
  file.c \
  filearch.c \
  fuse.c \
  guestfs_protocol.c \
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
  structs-cleanup.c \
  structs-compare.c \
  structs-copy.c \
  structs-free.c \
  tmpdirs.c \
  libguestfs.syms

GUESTFS_OBJECTS = $(GUESTFS_SOURCES:.c=.o)
GUESTFS_LIBRARY = guestfs

all: $(GUESTFS_LIBRARY)

$(GUESTFS_LIBRARY): $(GUESTFS_OBJECTS)
	$(CC) -shared -o lib$@.so $^

%.c.o:
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -fPIC -o $@ $<
