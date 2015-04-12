CC = gcc
PROTOC = protoc-c
RPCGEN = rpcgen
SED = sed
CPPFLAGS = -I.
CFLAGS = `pkg-config --cflags libprotobuf-c`
LIBS = `pkg-config --libs libprotobuf-c`
INCLUDES = \
  xdr.h \
  guestfs_protocol.h \
  guestfs_protocol.pb-c.h \
  guestfs_protocol_typedefs.h \
  guestfs_protocol_converters.h
SOURCES = \
  alloc.c \
  xdr.c \
  guestfs_protocol.pb-c.c \
  guestfs_protocol_converters.c \
  main.c
OBJECTS = $(SOURCES:.c=.o)
EXEC = test.exe

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $<

guestfs_protocol.pb-c.c: guestfs_protocol.proto
	$(PROTOC) --c_out=. $<

xdr.h: xdr.x
	rm -f $@-t
	$(RPCGEN) $(RPCGEN_DEFS) -h -o $@-t $<
	mv $@-t $@

xdr.c: xdr.x xdr.h
	rm -f $@-t $@-t2
	$(RPCGEN) $(RPCGEN_DEFS) -c -o $@-t $<
	$(SED) 's,\.\./\(\.\./\)*src,.,' < $@-t > $@-t2
	rm $@-t
	mv $@-t2 $@
	
clean:
	rm -f *.o

.PHONY: all clean
