CC = gcc
CFLAGS = -Wall
CPPFLAGS = -I.
LDFLAGS =
LIBS = 
EXEC = test
SOURCES = \
  ivshmem-write.c \
  main.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = \
  ivshmem-ops.h

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $(CXXFLAGS) -o $@ $<

clean:
	rm -f *.o *~

.PHONY: all clean

