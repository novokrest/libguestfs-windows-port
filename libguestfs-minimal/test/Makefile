CC = gcc -std=gnu99
CFLAGS = -I. -DGUESTFS_EXEC
CPPFLAGS = 
LDFLAGS = -L.
LIBS = -lmyguestfs

SOURCES = \
  test-guestfs.c \
  main.c
OBJECTS = $(SOURCES:.c=.o)
EXEC = test.exe

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o *~

.PHONY: all clean
